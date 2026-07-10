class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();
        int curSum = 0;
        int L = 0;
        int minLen = INT_MAX;
        for (int R = 0; R < n; ++R) {
            curSum += nums[R];
            while (curSum >= target) {
                minLen = min(minLen, (R - L + 1));
                curSum -= nums[L++];
            }
        }
        return minLen == INT_MAX? 0: minLen;
    }
};