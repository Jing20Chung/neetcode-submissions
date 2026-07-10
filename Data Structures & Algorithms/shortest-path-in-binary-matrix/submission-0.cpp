class Solution {
private:
    int bfs(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 1;

        static const int dr[8] = {0, 0, 1, -1, 1, -1, -1, 1};
        static const int dc[8] = {1, -1, 1, -1, -1, 1, 0, 0};
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int length = 1;
        while(!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto [r, c] = q.front();
                q.pop();
                for(int j = 0; j < 8; j++) {
                    int newR = r + dr[j];
                    int newC = c + dc[j];

                    if (newR >= n || newR < 0 || newC >= n || newC < 0 || grid[newR][newC] != 0) continue;
                    if (newR == n - 1 && newC == n - 1) return length + 1;

                    grid[newR][newC] = 1;
                    q.push({newR, newC});
                }
            }
            length++;
        }
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0][0] == 1 || grid[grid.size() - 1][grid.size() - 1] == 1) return -1;
        return bfs(grid);
    }
};