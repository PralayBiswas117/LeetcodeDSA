class Solution {
public:
    typedef long long ll;
    
    vector<vector<pair<int,int>>> adj;
    vector<vector<ll>> dp;
    int K;
    
    void dfs(int u, int parent) {
        
        ll base = 0;
        vector<ll> gains;
        
        for (auto &[v, w] : adj[u]) {
            if (v == parent) continue;
            
            dfs(v, u);
            
            base += dp[v][0];
            
            ll gain = (ll)w + dp[v][1] - dp[v][0];
            gains.push_back(gain);
        }
        
        sort(gains.rbegin(), gains.rend());
        
        dp[u][0] = base;
        int canTake = K;
        
        for (int i = 0; i < gains.size() && i < canTake; i++) {
            if (gains[i] > 0)
                dp[u][0] += gains[i];
        }
        
        dp[u][1] = base;
        canTake = K - 1;
        
        for (int i = 0; i < gains.size() && i < canTake; i++) {
            if (gains[i] > 0)
                dp[u][1] += gains[i];
        }
    }
    
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        
        int n = edges.size() + 1;
        K = k;
        
        adj.resize(n);
        dp.assign(n, vector<ll>(2, 0));
        
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        dfs(0, -1);
        
        return dp[0][0];
    }
};