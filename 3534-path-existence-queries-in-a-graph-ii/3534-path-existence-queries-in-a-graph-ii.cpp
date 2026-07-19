class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        const int LOG = 17; // because 2^17 > 1e5

        // {value, original index}
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort nodes by their values
        sort(arr.begin(), arr.end());

        // up[node][k] = node reachable after 2^k jumps
        vector<vector<int>> up(n, vector<int>(LOG));

        int r = n - 1;

        // Find the farthest reachable node for every node
        for (int l = n - 1; l >= 0; l--) {
            while (arr[r].first - arr[l].first > maxDiff) {
                r--;
            }

            int currentNode = arr[l].second;
            int farthestNode = arr[r].second;

            up[currentNode][0] = farthestNode;

            for (int k = 1; k < LOG; k++) {
                up[currentNode][k] =
                    up[up[currentNode][k - 1]][k - 1];
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            // Always move from smaller value to larger value
            if (nums[u] > nums[v]) {
                swap(u, v);
            }

            // Same node
            if (u == v) {
                answer.push_back(0);
                continue;
            }

            // Same value means direct edge exists
            if (nums[u] == nums[v]) {
                answer.push_back(1);
                continue;
            }

            int jumps = 0;

            // Try the largest jumps first
            for (int k = LOG - 1; k >= 0; k--) {
                int next = up[u][k];

                if (nums[next] < nums[v]) {
                    u = next;
                    jumps += (1 << k);
                }
            }

            // If even one jump cannot reach v, no path exists
            if (nums[up[u][0]] < nums[v]) {
                answer.push_back(-1);
            } else {
                answer.push_back(jumps + 1);
            }
        }

        return answer;
    }
};