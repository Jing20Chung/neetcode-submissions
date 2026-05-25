class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtracking(0, target, nums, cur, res);
        return res;
    }
private:
    void backtracking(int start, int target, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
        }

        for(int i = start; i < nums.size(); i++) {
            if(nums[i] <= target) {
                cur.push_back(nums[i]);
                backtracking(i, target - nums[i], nums, cur, res);
                cur.pop_back();
            }
            else {
                break;
            }
        }
    }
};
