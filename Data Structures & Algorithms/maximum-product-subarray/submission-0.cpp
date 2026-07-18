class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int curMax = 1;
        int curMin = 1;
        for(int i = 0; i < n; ++i) {
            int tmpMax = curMax * nums[i];
            int tmpMin = curMin * nums[i];
            curMax = max(nums[i], max(tmpMax, tmpMin));
            curMin = min(nums[i], min(tmpMax, tmpMin));
            res = max(res, curMax);
        }
        return res;
    }
};
