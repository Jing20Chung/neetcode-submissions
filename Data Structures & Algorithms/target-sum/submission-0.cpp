class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(totalSum * 2 + 1, INT_MIN));
        return backtrack(0, 0, totalSum, target, nums, dp);
    }

    int backtrack(int i, int sum, const int totalSum, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return sum == target? 1: 0;
        }

        if (dp[i][sum + totalSum] != INT_MIN) {
            return dp[i][sum + totalSum];
        }

        int add = backtrack(i + 1, sum + nums[i], totalSum, target, nums, dp);
        int sub = backtrack(i + 1, sum - nums[i], totalSum, target, nums, dp);
        dp[i][sum + totalSum] = add + sub;
        return dp[i][sum + totalSum];
    }
};
