class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int remainFresh = 0;
        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) remainFresh++;
            }
        }
        
        const int dr[] = {0, 0, 1, -1};
        const int dc[] = {1, -1, 0, 0};
        int mins = 0;
        while(!q.empty() && remainFresh > 0) {
            mins++;
            int qSize = q.size();
            for(int level = 0; level < qSize; level++) {
                auto [r, c] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nextR = r + dr[i];
                    int nextC = c + dc[i];

                    if (nextR < 0 || nextC < 0 || nextR >= grid.size() || nextC >= grid[0].size() || grid[nextR][nextC] != 1) continue;
                    grid[nextR][nextC] = 2;
                    q.push({nextR, nextC});
                    remainFresh--;
                }
            }
        }

        return remainFresh == 0? mins: -1;
    }
};
