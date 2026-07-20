class Solution {
public:
    vector<vector<string>> ans;
    
    vector<int> col;
    vector<int> diag1; // row - col
    vector<int> diag2; // row + col

    void solve(int row, int n, vector<string>& board) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            board[row][c] = 'Q';
            col[c] = 1;
            diag1[row - c + n - 1] = 1;
            diag2[row + c] = 1;

            solve(row + 1, n, board);

            board[row][c] = '.';
            col[c] = 0;
            diag1[row - c + n - 1] = 0;
            diag2[row + c] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        col.resize(n, 0);
        diag1.resize(2 * n - 1, 0);
        diag2.resize(2 * n - 1, 0);

        solve(0, n, board);

        return ans;
    }
};