class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxLen = 1;
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if (dp[r][c] == -1) {
                    dfs(r, c, m, n, matrix, dp);
                }
                maxLen = max(maxLen, dp[r][c]);
            }
        }
        return maxLen;
    }

    int dfs(int r, int c, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[r][c] != -1) return dp[r][c];
        static const int dr[4] = {1, -1, 0, 0};
        static const int dc[4] = {0, 0, 1, -1};

        int curVal = matrix[r][c];
        int maxVal = 1;
        for(int i = 0; i < 4; ++i) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            if (newR >= m || newR < 0 || newC >= n || newC < 0 || matrix[newR][newC] <= curVal) continue;
            maxVal = max(maxVal, 1 + dfs(newR, newC, m, n, matrix, dp));
        }
        dp[r][c] = maxVal;
        return dp[r][c];
    }
};
