class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int n, m;
    int ans = 0;

    void dfs(vector<vector<int>>& grid,
             int r, int c,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;
        // Check all 4 directions
        for(int i = 0; i < 4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];
            // Outside the grid
            if(newR < 0 || newR >= n ||
               newC < 0 || newC >= m) {
                ans++;
            }
            // Water cell
            else if(grid[newR][newC] == 0) {
                ans++;
            }
            // Unvisited land cell
            else if(!visited[newR][newC]) {
                dfs(grid, newR, newC, visited);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false)
        );

        // Find the first land cell
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, visited);
                    return ans;
                }
            }
        }
        return -1;
    }
};