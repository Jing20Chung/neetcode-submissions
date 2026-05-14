class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<unordered_set<char>> rows = vector<unordered_set<char>>(9);
        vector<unordered_set<char>> cols = vector<unordered_set<char>>(9);
        vector<unordered_set<char>> sqrs = vector<unordered_set<char>>(9);

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                char d = board[r][c];
                if (d != '.') {
                    int whichSqr = 3 * (r/3) + c/3;
                    if (rows[r].count(d) || cols[c].count(d) || sqrs[whichSqr].count(d)) {
                        return false;
                    }
                    rows[r].insert(d);
                    cols[c].insert(d);
                    sqrs[whichSqr].insert(d);
                }
            }
        }
        return true;
    }
};
