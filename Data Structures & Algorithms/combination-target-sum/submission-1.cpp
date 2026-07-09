class Solution {
private:
    void backtrack(const vector<int>& nums, int index, vector<int>& path, int target, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (index >= nums.size()) return;
        if (nums[index] > target) return;

        path.push_back(nums[index]);
        backtrack(nums, index, path, target - nums[index], ans);
        path.pop_back();
        backtrack(nums, index + 1, path, target, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, path, target, ans);
        return ans;
    }
};
