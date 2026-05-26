class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board[0].size(); c++) {
                if(solve(board, r, c, 0, word)) return true;
            }
        }
        return false;
    }
private:
    bool solve(vector<vector<char>>& board, int r, int c, int i, string& word) {
        if(i == word.size()) return true;

        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[i]) return false;

        char temp = board[r][c];
        board[r][c] = '#';
        bool res = solve(board, r + 1, c, i + 1, word) ||
                    solve(board, r - 1, c, i + 1, word) ||
                    solve(board, r, c + 1, i + 1, word) ||
                    solve(board, r, c - 1, i + 1, word);
        board[r][c] = temp;
        return res;
    }
};
