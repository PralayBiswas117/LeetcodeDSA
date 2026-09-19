class Solution {
public:

    int f(int r, int c, vector<vector<int>>& dungeon,
          vector<vector<int>>& dp) {

        int m = dungeon.size();
        int n = dungeon[0].size();

        if (r >= m || c >= n)
            return INT_MAX;

        if (r == m - 1 && c == n - 1)
            return max(1, 1 - dungeon[r][c]);

        if (dp[r][c] != -1)
            return dp[r][c];

        int right = f(r, c + 1, dungeon, dp);
        int down = f(r + 1, c, dungeon, dp);

        int next = min(right, down);

        return dp[r][c] = max(1, next - dungeon[r][c]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(0, 0, dungeon, dp);
    }
};