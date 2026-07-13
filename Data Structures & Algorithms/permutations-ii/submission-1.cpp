class Solution {
    void solve(vector<int>& nums, vector<int>& curr, vector<bool>& visited, vector<vector<int>>& ans) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(int j = 0; j < nums.size(); ++j) {
            if (visited[j]) continue;
            if (j > 0 && nums[j] == nums[j - 1] && !visited[j - 1]) continue;
            curr.push_back(nums[j]);
            visited[j] = true;
            solve(nums, curr, visited, ans);
            visited[j] = false;
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) return {};
        sort(nums.begin(), nums.end());
        int n = std::ssize(nums);
        vector<vector<int>> ans;
        vector<bool> visited(n, false);
        vector<int> curr;
        solve(nums, curr, visited, ans);
        return ans;
    }
};