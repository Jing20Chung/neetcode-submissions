class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;

        const int dr[4] = {1, -1, 0, 0};
        const int dc[4] = {0, 0, 1, -1};

        queue<pair<int, int>> q;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        q.push({0, 0});
        seen[0][0] = true;
        int steps = 0;
        while(!q.empty()) {
            int qSize = q.size();
            for(int i = 0; i < qSize; ++i) {
                auto [r, c] = q.front();
                q.pop();
                if (r == m - 1 && c == n - 1) return steps;
                for(int j = 0; j < 4; ++j) {
                    int newR = r + dr[j];
                    int newC = c + dc[j];

                    if (newR < 0 || newR >= m || newC < 0 || newC >= n || seen[newR][newC] || grid[newR][newC] != 0) continue;
                    seen[newR][newC] = true;
                    q.push({newR, newC});
                }
            }
            ++steps;
        }
        return -1;
    }
};
