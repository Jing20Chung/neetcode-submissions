class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num: nums) {
            totalSum += num;
        }
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for(int num: nums) {
            for(int s = target; s >= num; s--) {
                dp[s] = dp[s] || dp[s - num]; // skip num, already form sum s || take this num, current sum is s - num, so it can form s
            }
            if (dp[target]) return true;
        }

        return false;
    }
};
