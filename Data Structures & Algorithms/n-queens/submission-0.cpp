class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2*n, false);
        vector<bool> diag2(2*n, false);
        solve(0, n, board, res, col, diag1, diag2);
        return res;
    }
private:
    void solve(int r, int n, vector<string>& board, vector<vector<string>>& res, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2) {
        if(r == board.size()) {
            res.push_back(board);
            return;
        }

        for(int c = 0; c < board.size(); c++) {
            if (!col[c] && !diag1[r - c + n] && !diag2[r + c]) {
                board[r][c] = 'Q';
                col[c] = diag1[r - c + n] = diag2[r + c] = true;
                solve(r + 1, n, board, res, col, diag1, diag2);
                board[r][c] = '.';
                col[c] = diag1[r - c + n] = diag2[r + c] = false;
            }
        }
    }
};
