class Solution {
public:
    const int dr[4] = {0, 0, 1, -1};
    const int dc[4] = {1, -1, 0, 0};
    int ROWS, COLS;
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        for(int r = 0; r < ROWS; r++) {
            if (board[r][0] == 'O') {
                dfs(r, 0, board);
            }
            if (board[r][COLS - 1] == 'O') {
                dfs(r, COLS - 1, board);
            }
        }

        for(int c = 0; c < COLS; c++) {
            if (board[0][c] == 'O') {
                dfs(0, c, board);
            }
            if (board[ROWS - 1][c] == 'O') {
                dfs(ROWS - 1, c, board);
            }
        }

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }

    void dfs(int r, int c, vector<vector<char>>& board) {
        board[r][c] = 'T';

        for(int i = 0; i < 4; i++) {
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            if(nextR < 0 || nextC < 0 || nextR >= ROWS || nextC >= COLS || board[nextR][nextC] != 'O') continue;
            dfs(nextR, nextC, board);
        }
    }
};
