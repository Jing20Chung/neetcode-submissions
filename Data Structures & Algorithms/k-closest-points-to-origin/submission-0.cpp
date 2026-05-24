class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> q;

        for(int i = 0; i < points.size(); i++) {
            int disSq = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            q.push({disSq, i});

            if (q.size() > k) q.pop();
        }
        vector<vector<int>> res;
        while(!q.empty()) {
            res.push_back(points[q.top().second]);
            q.pop();
        }
        return res;
    }
};
