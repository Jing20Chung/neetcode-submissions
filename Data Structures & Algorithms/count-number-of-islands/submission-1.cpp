class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c, const int m, const int n) {
        grid[r][c] = '0';
        static const int dr[4] = {1, -1, 0, 0};
        static const int dc[4] = {0, 0, 1, -1};
        for(int i = 0; i < 4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            if (newR >= m || newR < 0 || newC >= n || newC < 0 || grid[newR][newC] != '1') continue;
            dfs(grid, newR, newC, m, n);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};
