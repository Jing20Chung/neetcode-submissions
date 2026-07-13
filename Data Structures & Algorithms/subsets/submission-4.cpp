class Solution {
    void buildSubsets(vector<vector<int>>& ans, int i, vector<int>& nums, vector<int> curr) {
        if (i >= nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        buildSubsets(ans, i + 1, nums, curr);
        curr.pop_back();
        buildSubsets(ans, i + 1, nums, curr);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        buildSubsets(ans, 0, nums, curr);
        return ans;        
    }
};
