class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int r, c;

    // DFS 재귀 함수
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int x, int y) {
        // 1. 기저 조건(Base condition): 범위를 벗어나거나, 물이거나, 이미 방문한 경우 종료
        if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] == '0' || vis[x][y]) {
            return;
        }

        // 2. 방문 처리
        vis[x][y] = true;

        // 3. 4방향 재귀 탐색
        for (int dir = 0; dir < 4; dir++) {
            dfs(grid, vis, x + dx[dir], y + dy[dir]);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0; 
        r = grid.size();
        c = grid[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    dfs(grid, vis, i, j); // 육지를 발견하면 DFS 시작
                }
            }
        }
        return ans;
    }
};