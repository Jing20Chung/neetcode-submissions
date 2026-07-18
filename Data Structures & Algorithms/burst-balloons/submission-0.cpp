class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> newNums;
        newNums.reserve(nums.size() + 2);
        newNums.push_back(1);
        newNums.insert(newNums.end(), nums.begin(), nums.end());
        newNums.push_back(1);
        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, -1));
        return dfs(1, newNums.size() - 2, newNums, dp);
    }

    int dfs(int l, int r, vector<int>& nums, vector<vector<int>>& dp) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        
        for(int i = l; i <= r; ++i) {
            dp[l][r] = max(dp[l][r], nums[l - 1] * nums[i] * nums[r + 1] + dfs(l, i - 1, nums, dp) + dfs(i + 1, r, nums, dp));
        }
        return dp[l][r];
    }
};
