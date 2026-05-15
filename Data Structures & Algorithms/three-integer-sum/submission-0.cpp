class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int target = -nums[i];
                int l = i + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    long twoSum = nums[l] + nums[r];
                    if (twoSum < target) {
                        l++;
                    }
                    else if (twoSum > target) {
                        r--;
                    }
                    else {
                        result.push_back({nums[i], nums[l], nums[r]});
                        while (nums[l] == nums[l + 1]) l++;
                        while (nums[r] == nums[r - 1]) r--;
                        l++;
                        r--;
                    }
                }
            }
        }

        return result;
    }
};
