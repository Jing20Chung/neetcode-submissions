class Solution {
    struct CompareInterval {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first != b.first) return a.first > b.first;
            else return a.second > b.second;
        }
    };
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // sort intervals by its start time
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){return a[0] < b[0];});

        // sort queries acendingly
        vector<pair<int, int>> newQ;
        int n = queries.size();
        newQ.reserve(n);
        for(int i = 0; i < n; ++i) {
            newQ.push_back({queries[i], i});
        }
        sort(newQ.begin(), newQ.end(), [](const auto& a, const auto& b){return a.first < b.first;});

        // use min heap to get the min interval
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareInterval> pq;

        // build solution
        vector<int> res(n, -1);
        // track used interval index
        int k = 0;
        // loop through queries
        for(auto& [query, index]: newQ) {
            while(k < intervals.size() && intervals[k][0] <= query) {
                int s = intervals[k][0];
                int e = intervals[k][1];
                pq.push({e - s + 1, e});
                ++k;
            }

            while(!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            if (!pq.empty()) {
                res[index] = pq.top().first;
            }
        }

        return res;
    }
};
