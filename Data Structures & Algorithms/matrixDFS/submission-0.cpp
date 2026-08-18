class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return 0;
        return dfs(0, 0, n, m, grid);
    }

    int dfs(int r, int c, int n, int m, vector<vector<int>>& grid) {
        if (r == n - 1 && c == m - 1) return 1;
        grid[r][c] = -1;
        int result = 0;
        for(int i = 0; i < 4; ++i) {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if (newR < 0 || newR >= n || newC < 0 || newC >= m || grid[newR][newC] != 0) continue;
            result += dfs(newR, newC, n, m, grid);
            
        }
        grid[r][c] = 0;
        return result;
    }

private:
    const int dr[4] = {1, -1, 0, 0};
    const int dc[4] = {0, 0, 1, -1};
};
