class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c, const int m, const int n) {
        static const int dr[4] = {1, -1, 0, 0};
        static const int dc[4] = {0, 0, 1, -1};
        int area = 1;
        grid[r][c] = 0;
        for(int i = 0; i < 4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            if (newR >= m || newR < 0 || newC >= n || newC < 0 || grid[newR][newC] != 1) continue;
            area += dfs(grid, newR, newC, m, n);
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    maxArea = max(maxArea, dfs(grid, r, c, m, n));
                }
            }
        }

        return maxArea;
    }
};
