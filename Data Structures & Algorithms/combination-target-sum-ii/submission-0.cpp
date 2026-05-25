class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtracking(0, target, candidates, cur, res);
        return res;
    }
private:
    void backtracking(int start, int target, vector<int>& candidates, vector<int>& cur, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if(candidates[i] <= target) {
                cur.push_back(candidates[i]);
                backtracking(i + 1, target - candidates[i], candidates, cur, res);
                cur.pop_back();
            }
            else {
                break;
            }
        }
    }
};
