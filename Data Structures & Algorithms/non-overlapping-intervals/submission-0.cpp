class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        int res = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});

        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            if (prevEnd <= intervals[i][0]) {
                prevEnd = intervals[i][1];
            }
            else {
                res++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
        }
        return res;
    }
};
