class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                int l = i + 1, r = n - 1;
                int target = -nums[i];
                while (l < r) {
                    int sum = nums[l] + nums[r];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[l], nums[r]});
                        ++l;
                        --r;
                        while(l < r && nums[l - 1] == nums[l]) ++l;
                    }
                    else if (sum < target) {
                        ++l;
                    }
                    else {
                        --r;
                    }
                }
            }
        }
        return ans;
    }
};
