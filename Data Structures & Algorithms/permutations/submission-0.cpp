class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0, nums, res);
        return res;
    }
private:
    void solve(int start, vector<int>& nums, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            solve(start + 1, nums, res);
            swap(nums[start], nums[i]);
        }
    }
};
