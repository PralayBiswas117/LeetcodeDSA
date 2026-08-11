class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> engineers;

        for (int i = 0; i < n; i++)
            engineers.push_back({efficiency[i], speed[i]});

        sort(engineers.begin(), engineers.end(), greater<pair<int, int>>());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long speedSum = 0;
        long long ans = 0;
        const int MOD = 1e9 + 7;

        for (auto& e : engineers) {
            int eff = e.first;
            int sp = e.second;

            pq.push(sp);
            speedSum += sp;

            if (pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }

            ans = max(ans, speedSum * eff);
        }

        return ans % MOD;
    }
};