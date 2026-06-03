class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        const int dr[] = {1, -1, 0, 0};
        const int dc[] = {0, 0, -1, 1};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        visited[0][0] = true;
        q.push({grid[0][0], 0, 0}); // t, r, c

        while(!q.empty()) {
            vector<int> top = q.top();
            q.pop();
            int t = top[0], r = top[1], c = top[2];

            if (r == n - 1 && c == n - 1) return t;

            for(int i = 0; i < 4; i++) {
                int nextR = r + dr[i];
                int nextC = c + dc[i];

                if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= n || visited[nextR][nextC]) continue;

                visited[nextR][nextC] = true;
                q.push({max(t, grid[nextR][nextC]), nextR, nextC});
            }
        }
        return -1;
    }
};
