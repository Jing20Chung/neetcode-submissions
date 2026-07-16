class Solution {
public:
    int numDistinct(string s, string t) {
        // english letters: [a-z][A-Z]
        if (s.size() < t.size()) return 0;
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0, s, t, dp);

    }

    int dfs(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int res = dfs(i + 1, j, s, t, dp);
        if (s[i] == t[j]) {
            res += dfs(i + 1, j + 1, s, t, dp);
        }

        dp[i][j] = res;
        return res;
    }
};
