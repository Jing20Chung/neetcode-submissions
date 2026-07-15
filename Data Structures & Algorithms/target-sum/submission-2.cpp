class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 0-1 knapsack
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum < target) return 0; // if all num add together still can't reach to target, there is no way we can find the answer.

        unordered_map<int, int> dp; // sum, count
        dp[0] = 1; // when sum == 0, the possible way is 1
        for(int num: nums) {
            unordered_map<int, int> nextDp;
            for(auto [sum, count]: dp) {
                nextDp[sum + num] += count;
                nextDp[sum - num] += count;
            }
            dp = nextDp;
        }
        return dp[target];
    }
};
