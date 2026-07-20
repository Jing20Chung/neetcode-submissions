class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        vector<vector<int>> res;
        for(auto& interval: intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back({interval[0], interval[1]});
            }
            else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};
