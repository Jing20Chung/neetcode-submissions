class Solution {
    void solve(int i, vector<int>& nums, int target, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (i >= nums.size()) {
            return;
        }

        // choose this nums[i] without increasing the index
        // means this index still can be used in the next round
        if (target >= nums[i]) {
            curr.push_back(nums[i]);
            solve(i, nums, target - nums[i], curr, ans);
            curr.pop_back();
        }
        
        // skip this index
        solve(i + 1, nums, target, curr, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, nums, target, curr, ans);
        return ans;
    }
};
