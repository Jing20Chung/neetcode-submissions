class Solution {
    void build(vector<vector<int>>& ans, vector<int>& nums, int i, vector<int> curr) {
        if (i >= nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        build(ans, nums, i + 1, curr);
        curr.pop_back();

        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        build(ans, nums, i + 1, curr);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        build(ans, nums, 0, curr);
        return ans;
    }
};
