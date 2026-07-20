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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){return a.start < b.start;});
        priority_queue<int, vector<int>, greater<>> pq;
        int count = 0;
        for(const auto& interval: intervals) {
            while(!pq.empty() && pq.top() <= interval.start) {
                pq.pop();
            }
            pq.push(interval.end);
            count = max(count, (int) pq.size());
        }   

        return count;
    }
};
