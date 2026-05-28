class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int dr[] = {0, 0, 1, -1};
        const int dc[] = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nextR = r + dr[i];
                int nextC = c + dc[i];

                if (nextR < 0 || nextC < 0 || nextR >= grid.size() || 
                nextC >= grid[0].size() || grid[nextR][nextC] == -1 || 
                grid[nextR][nextC] == 0 || grid[nextR][nextC] != INT_MAX) continue;
                grid[nextR][nextC] = grid[r][c] + 1;
                q.push({nextR, nextC});
            }
        }
    }
};
