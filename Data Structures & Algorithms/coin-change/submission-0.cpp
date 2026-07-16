class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int a = 1; a <= amount; ++a) {
            for(int coin: coins) {
                if ((a - coin) >= 0) {
                    dp[a] = min(dp[a - coin] + 1, dp[a]);
                }
            }
        }

        return dp[amount] == amount + 1? -1: dp[amount];
    }
};
