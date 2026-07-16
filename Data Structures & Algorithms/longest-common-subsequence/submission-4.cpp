class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        if (len1 > len2) return longestCommonSubsequence(text2, text1);

        vector<int> dp(len1 + 1, 0);

        for(int i = 0; i < len2; ++i) {
            vector<int> nextDp(len1 + 1, 0);
            for(int j = 0; j < len1; ++j) {
                if (text2[i] == text1[j]) {
                    nextDp[j + 1] = dp[j] + 1;
                }
                else {
                    nextDp[j + 1] = max(nextDp[j], dp[j + 1]);
                }
            }
            dp = nextDp;
        }

        return dp[len1];
    }
};
