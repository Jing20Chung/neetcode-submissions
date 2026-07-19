class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(0, 0, s, p, dp);
    }

    bool dfs(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (j == p.size()) return i == s.size();
        if (dp[i][j] != -1) return dp[i][j];

        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        bool result = false;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            result = (dfs(i, j + 2, s, p, dp) || (first_match && dfs(i + 1, j, s, p, dp)));
        }
        else {
            result = first_match && dfs(i + 1, j + 1, s, p, dp);
        }
        dp[i][j] = result;
        return result;
    }
};
