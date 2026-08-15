class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        vector<int> dp(target + 1, -1);
        return solve(0, nums, target, dp);
    }

    int solve(int curSum, vector<int>& nums, const int target, vector<int>& dp) {
        if (dp[curSum] != -1) return dp[curSum];
        int count = 0;
        int tempSum = curSum;
        for(int num: nums) {
            tempSum += num;
            if (tempSum == target) {
                ++count;
            }
            else if (tempSum > target) break;
            else {
                count += solve(tempSum, nums, target, dp);
            }
            tempSum -= num;
        }
        dp[curSum] = count;
        return count;
    }
};