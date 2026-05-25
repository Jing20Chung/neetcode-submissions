class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        solve(0, nums, cur, res);
        return res;
    }
private:
    void solve(int start, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);

        for(int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            cur.push_back(nums[i]);
            solve(i + 1, nums, cur, res);
            cur.pop_back();
        }
    }
};
