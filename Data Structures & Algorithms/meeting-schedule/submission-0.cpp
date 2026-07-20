/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        //[start, end)
        if (intervals.empty()) return true;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){return a.start < b.start;});
        // determine if there is any overlapping intervals
        for(int i = 1; i < intervals.size(); ++i) {
            if (intervals[i - 1].end > intervals[i].start) return false;
        }

        return true;
    }
};
