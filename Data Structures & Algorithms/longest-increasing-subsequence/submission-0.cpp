class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1); // initialized as 1
        int maxLIS = 1;
        for(int i = n - 2; i >= 0; --i) {
            for(int j = i + 1; j < n; ++j) {
                if (nums[i] < nums[j]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
            maxLIS = max(maxLIS, LIS[i]);
        }

        return maxLIS;
    }
};
