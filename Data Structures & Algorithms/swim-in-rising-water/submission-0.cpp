class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        int minH = INT_MAX, maxH = INT_MIN;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                minH = min(minH, grid[r][c]);
                maxH = max(maxH, grid[r][c]);
            }
        }

        int l = minH, r = maxH;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (dfs(0, 0, mid, visited, grid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }

            for(int r = 0; r < n; r++) {
                fill(visited[r].begin(), visited[r].end(), false);
            }
        }
        return r;
    }

    bool dfs(int r, int c, int t, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        int n = grid.size();
        if (r < 0 || r >= n || c >= n || c < 0 || visited[r][c] || grid[r][c] > t) return false;

        if (r == n - 1 && c == n - 1) return true;

        visited[r][c] = true;
        if (dfs(r + 1, c, t, visited, grid) || dfs(r - 1, c, t, visited, grid) ||
            dfs(r, c + 1, t, visited, grid) || dfs(r, c - 1, t, visited, grid))
            return true;
        else return false;
    }
};
