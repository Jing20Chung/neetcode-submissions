class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    int curArea = 0;
                    dfs(r, c, curArea, grid);
                    maxArea = max(maxArea, curArea);
                }
            }
        }

        return maxArea;
    }

private:
    void dfs(int r, int c, int& area, vector<vector<int>>& grid) {
        area++;
        grid[r][c] = 0;

        const int dr[] = {0, 0, 1, -1};
        const int dc[] = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++) {
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            if (nextR < 0 || nextC < 0 || nextR >= grid.size() || nextC >= grid[0].size() || grid[nextR][nextC] == 0) continue;
            dfs(nextR, nextC, area, grid);
        }
    }
};
