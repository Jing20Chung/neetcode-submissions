class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int sqr[9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                int s = 3 * (r/3) + c/3;
                int mask = 1 << (board[r][c] - '1');
                if (row[r] & mask || col[c] & mask || sqr[s] & mask) return false;

                row[r] |= mask;
                col[c] |= mask;
                sqr[s] |= mask;
            }
        }
        return true;
    }
};
