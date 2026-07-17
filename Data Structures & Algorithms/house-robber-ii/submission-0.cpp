class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return max(dfs(0, 1, nums, dp), dfs(1, 0, nums, dp));
    }

    int dfs(int i, int is1robbed, vector<int>& nums, vector<vector<int>>& dp) {
        if (i >= nums.size()) return 0;
        if (i == nums.size() - 1 && is1robbed == 1) return 0;
        if (dp[i][is1robbed] != -1) return dp[i][is1robbed];

        dp[i][is1robbed] = max(dfs(i + 1, is1robbed, nums, dp), dfs(i + 2, is1robbed, nums, dp) + nums[i]);
        return dp[i][is1robbed];
    }
};
