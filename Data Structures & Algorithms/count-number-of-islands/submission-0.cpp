class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numOfIsland = 0;

        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    numOfIsland++;
                    dfs(r, c, grid);
                }
            }
        }
        return numOfIsland;
    }

private:
    void dfs(int r, int c, vector<vector<char>>& grid) {
        grid[r][c] = '0';

        const int dr[] = {0, 0, 1, -1};
        const int dc[] = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++) {
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            if (nextR < 0 || nextC < 0 || nextR >= grid.size() || nextC >= grid[0].size() || grid[nextR][nextC] == '0') continue;
            dfs(nextR, nextC, grid);
        }
    }
};
