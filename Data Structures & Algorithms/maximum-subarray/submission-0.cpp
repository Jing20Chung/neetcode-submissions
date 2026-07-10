class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = 0;
        for(int num: nums) {
            curSum = (max(curSum, 0) + num);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
