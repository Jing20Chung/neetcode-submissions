class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return dfs(0, 0, s1, s2, s3, dp);
    }

    bool dfs(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if (i + j == s3.size()) {
            return (i == s1.size() && j == s2.size());
        }
        if (dp[i][j] != -1) return dp[i][j];

        bool res = false;
        if (i < s1.size() && s1[i] == s3[i + j]) {
            res = dfs(i + 1, j, s1, s2, s3, dp);
        }

        if (!res && j < s2.size() && s2[j] == s3[i + j]) {
            res = dfs(i, j + 1, s1, s2, s3, dp);
        }
        dp[i][j] = res;
        return res;
    }
};
