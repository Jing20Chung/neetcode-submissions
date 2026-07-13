class Solution {
    void solve(int i, int n, int k, vector<int>& curr, vector<vector<int>>& ans) {
        if (curr.size() >= k) {
            ans.push_back(curr);
            return;
        }
        if (i >= n + 1) {
            return;
        }

        curr.push_back(i);
        solve(i + 1, n, k, curr, ans);
        curr.pop_back();
        solve(i + 1, n, k, curr, ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, n, k, curr, ans);
        return ans;
    }
};