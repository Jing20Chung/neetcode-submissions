class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, const vector<int>& nums, int index) {
        if (index >= nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        backtrack(ans, curr, nums, index + 1);
        curr.pop_back();
        backtrack(ans, curr, nums, index + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, nums, 0);
        return ans;
    }
};
