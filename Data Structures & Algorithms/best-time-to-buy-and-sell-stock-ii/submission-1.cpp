class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy or not
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, prices, dp);
    }

    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        // hold
        int result = solve(i + 1, buy, prices, dp);
        // buy
        if (buy == 0) {
            result = max(result, solve(i + 1, 1, prices, dp) - prices[i]);
        }
        else { // sell
            result = max(result, solve(i + 1, 0, prices, dp) + prices[i]);
        }
        dp[i][buy] = result;
        return result;
    }
};