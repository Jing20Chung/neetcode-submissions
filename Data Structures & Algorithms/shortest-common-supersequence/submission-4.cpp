class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // build LCS map
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // from bottom-right corner
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        // pick char
        int i = 0, j = 0;
        string res = "";
        while (i < m && j < n) {
            if (str1[i] == str2[j]) {
                res.push_back(str1[i]);
                ++i;
                ++j;
            }
            else if (dp[i + 1][j] >= dp[i][j + 1]) { // the LCS of str[i + 1:] and str2[j:] is greater or equal to LCS of str[i:] and str2[j + 1:]
                // choose to skip str1[i]
                res.push_back(str1[i]);
                ++i;
            }
            else {
                res.push_back(str2[j]);
                ++j;
            }
        }

        // see if there is any remaining char in each str
        while(i < m) {
            res.push_back(str1[i]);
            ++i;
        }

        while(j < n) {
            res.push_back(str2[j]);
            ++j;
        }

        return res;
    }
};