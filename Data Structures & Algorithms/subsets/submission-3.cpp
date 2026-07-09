class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int size = (int) res.size();
            for(int j = 0; j < size; j++) {
                vector<int> subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
        }
        return res;
    }
};
