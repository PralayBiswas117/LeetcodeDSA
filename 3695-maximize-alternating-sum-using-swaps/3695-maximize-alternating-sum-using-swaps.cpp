class Solution {
public:
    // DFS to collect all indices in the same connected component
    void dfs(int u, vector<bool>& vis, vector<int>& cmp, vector<vector<int>>& adj) {
        vis[u] = true;       // Mark current node as visited
        cmp.push_back(u);    // Add index to current component
        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs(v, vis, cmp, adj); // Recur for unvisited neighbors
            }
        }
    }

    long long maxAlternatingSum(vector<int>& v1, vector<vector<int>>& sw) {
        int n = v1.size();
    vector<vector<int>> adj(n); // Adjacency list for swap connections

        // Build the graph from swaps
        for (auto it : sw) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false); // Visited array for DFS
        for (int u = 0; u < n; u++) {
            if (!vis[u]) {
               vector<int> cmp; // Stores all indices in the component
                dfs(u, vis, cmp, adj);
                // Collect the values of the current component
                vector<int> val;
                for (auto ind : cmp) val.push_back(v1[ind]);

                // Sort values desc to place largest at even indices
                sort(val.rbegin(), val.rend());
                int l = 0, r = cmp.size() - 1;
                for (auto ind : cmp) {
                    if (ind % 2 == 0) {
                        v1[ind] = val[l++]; // Largest values to even indices
                    } else {
                        v1[ind] = val[r--]; // Smallest values to odd indices
                    }
                }
            }
        }
        // Compute the final alternating sum
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) ans += v1[i]; // Add even index
            else ans -= v1[i];            // Subtract odd index
        }

        return ans;
    }
};