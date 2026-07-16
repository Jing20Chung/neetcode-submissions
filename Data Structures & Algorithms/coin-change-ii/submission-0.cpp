class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return dfs(0, 0, amount, coins, dp);        
    }

    int dfs(int i, int curAmount, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (curAmount == amount) return 1;
        if (i == coins.size() || curAmount > amount) return 0;
        if (dp[i][curAmount] != -1) return dp[i][curAmount];
        return dp[i][curAmount] = dfs(i, curAmount + coins[i], amount, coins, dp) + dfs(i + 1, curAmount, amount, coins, dp);
    }
};
