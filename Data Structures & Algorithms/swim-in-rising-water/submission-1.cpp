class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int curVersion = 0;
        int minH = INT_MAX, maxH = INT_MIN;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                minH = min(minH, grid[r][c]);
                maxH = max(maxH, grid[r][c]);
            }
        }

        int l = minH, r = maxH;
        while(l < r) {
            curVersion++;
            int mid = l + (r - l) / 2;
            if (dfs(0, 0, mid, curVersion, visited, grid)) {
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

    bool dfs(int r, int c, int t, int curV, vector<vector<int>>& visited, vector<vector<int>>& grid) {
        int n = grid.size();
        if (r < 0 || r >= n || c >= n || c < 0 || visited[r][c] == curV || grid[r][c] > t) return false;

        if (r == n - 1 && c == n - 1) return true;

        visited[r][c] = curV;
        if (dfs(r + 1, c, t, curV, visited, grid) || dfs(r - 1, c, t, curV, visited, grid) ||
            dfs(r, c + 1, t, curV, visited, grid) || dfs(r, c - 1, t, curV, visited, grid))
            return true;
        else {
            return false;
        }
    }
};
