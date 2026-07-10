class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        if (m == 0 || n == 0) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(text1, 0, text2, 0, dp, m, n);
    }
private:
    int dfs(const string& text1, int i, const string& text2, int j, vector<vector<int>>& dp, const int m, const int n) {
        if (i == m || j == n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + dfs(text1, i + 1, text2, j + 1, dp, m, n);
        }
        else {
            dp[i][j] = max(dfs(text1, i, text2, j + 1, dp, m, n), dfs(text1, i + 1, text2, j, dp, m, n));
        }
        return dp[i][j];
    }
};
