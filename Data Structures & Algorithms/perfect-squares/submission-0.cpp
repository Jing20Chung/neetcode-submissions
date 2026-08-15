class Solution {
public:
    int numSquares(int n) {
        vector<int> candidates;
        for(int i = sqrt(n); i > 0; --i) {
            candidates.push_back(i * i);
        }

        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int num: candidates) {
                if (i - num >= 0) {
                    dp[i] = min(dp[i], dp[i - num] + 1);
                }
            }
        }
        return dp[n];
    }
};