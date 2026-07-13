class Solution {
    void solve(vector<vector<int>>& ans, unordered_map<int, int>& numCount, vector<int>& curr, int remain) {
        if (remain == 0) {
            ans.push_back(curr);
            return;
        }

        for(auto& [num, count]: numCount) {
            if (count != 0) {
                numCount[num]--;
                curr.push_back(num);
                solve(ans, numCount, curr, remain - 1);
                curr.pop_back();
                numCount[num]++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) return {};
        unordered_map<int, int> numCount;
        for(int num: nums) {
            if (!numCount.contains(num)) {
                numCount[num] = 1;
            }
            else {
                numCount[num]++;
            }
        }

        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, numCount, curr, nums.size());
        return ans;
    }
};