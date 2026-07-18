class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return dfs(0, true, dp, prices);
    }

    int dfs(int i, bool buy, vector<vector<int>>& dp, vector<int>& prices) {
        if (i >= prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        int idleResult = dfs(i + 1, buy, dp, prices);
        if (buy) { // I can buy or not buy
            int buyResult = dfs(i + 1, !buy, dp, prices) - prices[i];
            dp[i][buy] = max(buyResult, idleResult);
        }
        else { // I can sell or not sell
            int sellResult = dfs(i + 2, !buy, dp, prices) + prices[i];
            dp[i][buy] = max(sellResult, idleResult);
        }

        return dp[i][buy];
    }
};
