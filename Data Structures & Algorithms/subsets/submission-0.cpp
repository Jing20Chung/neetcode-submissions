class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(0, nums, res, cur);

        return res;
    }
private:
    void dfs(int i, vector<int>& nums, vector<vector<int>>& res, vector<int>& cur) {
        if (i >= nums.size()) {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(i + 1, nums, res, cur);

        cur.pop_back();
        dfs(i + 1, nums, res, cur);
        return;
    }
};
