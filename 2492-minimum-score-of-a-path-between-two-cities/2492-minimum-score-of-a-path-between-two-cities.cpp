class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<bool> visited(n + 1, false);
        int answer = INT_MAX;

        dfs(1, graph, visited, answer);

        return answer;
    }

private:
    void dfs(int node,
             vector<vector<pair<int, int>>>& graph,
             vector<bool>& visited,
             int& answer) {

        visited[node] = true;

        for (auto [next, weight] : graph[node]) {
            answer = min(answer, weight);

            if (!visited[next]) {
                dfs(next, graph, visited, answer);
            }
        }
    }
};