class Solution {
public:
    int n;
    long long K;
    vector<vector<pair<int, int>>> graph;

    bool check(int minScore) {
        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost != dist[node])
                continue;

            if (cost > K)
                continue;

            if (node == n - 1)
                return true;

            for (auto [next, edgeCost] : graph[node]) {
                if (edgeCost < minScore)
                    continue;

                long long newCost = cost + edgeCost;

                if (newCost < dist[next] && newCost <= K) {
                    dist[next] = newCost;
                    pq.push({newCost, next});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {
        n = online.size();
        K = k;

        graph.assign(n, {});

        int low = INT_MAX;
        int high = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if (!online[u] || !online[v])
                continue;

            graph[u].push_back({v, cost});

            low = min(low, cost);
            high = max(high, cost);
        }

        if (low == INT_MAX)
            return -1;

        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return answer;
    }
};