class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int INF = 1E9;
        int n = dist.size();
        vector<vector<int>> DP(n, vector<int>(n));
        DP[0][0] = dist[0];
        for (int i = 1; i < n; i++)
            for (int skips = 0; skips <= i; skips++) {
                int d1 = skips == 0 ? INF :  DP[i - 1][skips - 1] + dist[i];
                int d2 = skips == i ? INF : (DP[i - 1][skips] + speed - 1) / speed * speed + dist[i];
                DP[i][skips] = min(d1, d2);
            }
        for (int skips = 0; skips < n; skips++)
            if (DP[n - 1][skips] <= 1LL * speed * hoursBefore) return skips;
        return -1;
    }
};