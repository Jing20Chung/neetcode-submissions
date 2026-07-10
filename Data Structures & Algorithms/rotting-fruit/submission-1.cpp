class Solution {
private:
    int bfs(vector<vector<int>>& grid) {
        int minute = 0;
        int freshCnt = 0;
        static const int dr[4] = {0, 0, 1, -1};
        static const int dc[4] = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if (grid[r][c] == 1) freshCnt++;
                if (grid[r][c] == 2) q.push({r, c});
            }
        }

        if (freshCnt == 0) return 0;

        while(!q.empty()) {
            int qSize = q.size();
            bool anyCorrupt = false;
            for(int i = 0; i < qSize; i++) {
                auto [r, c] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++) {
                    int newR = r + dr[j];
                    int newC = c + dc[j];

                    if (newR >= m || newR < 0 || newC >= n || newC < 0 || grid[newR][newC] != 1) continue;
                    anyCorrupt = true;
                    grid[newR][newC] = 2;
                    freshCnt--;
                    q.push({newR, newC});
                }
            }
            if (anyCorrupt) minute++;
        }

        return freshCnt == 0? minute: -1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;
        // 0 == empty
        // 1 == fresh
        // 2 == rotten
        // multiple source
        // four directionally
        // remain fresh count
        // go through grid to find those
        // push source into queue
        // run bfs
        // return if the remain count == 0
        return bfs(grid);
    }
};
