class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp;
        dp.reserve(nums.size());
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]);
                continue;
            }

            int idx = binarySearch(nums[i], dp);
            dp[idx] = nums[i];
        }
        return dp.size();
    }

    int binarySearch(int target, vector<int>& dp) {
        int l = 0;
        int r = dp.size() - 1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if (dp[mid] >= target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};
