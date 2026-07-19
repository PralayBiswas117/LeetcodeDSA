class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        // Starting cell also costs grid[0][0]
        health -= grid[0][0];

        if (health <= 0) {
            return false;
        }

        q.push({0, 0});
        best[0][0] = health;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n) {

                    int newHealth =
                        best[r][c] - grid[nr][nc];

                    if (newHealth > 0 &&
                        newHealth > best[nr][nc]) {

                        best[nr][nc] = newHealth;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return false;
    }
};