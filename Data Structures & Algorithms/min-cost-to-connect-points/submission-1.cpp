class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;

        int n = points.size();
        // build path cost map
        vector<vector<pair<int, int>>> path(n);
        for(int i = 0; i < points.size(); ++i) {
            for(int j = i; j < points.size(); ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                path[i].push_back({dist, j});
                path[j].push_back({dist, i});
            }
        }

        // need a vector to know which point has been visited
        vector<bool> visited(n, false);

        // need a minHeap to keep track the min cost path
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
        heap.push({0, 0});

        int cost = 0;

        while(!heap.empty()) {
            auto [dist, node] = heap.top(); heap.pop();
            if (visited[node]) continue;
            cost += dist;
            visited[node] = true;
            for(const auto&[neiDist, nei]: path[node]) {
                if (!visited[nei]) {
                    heap.push({neiDist, nei});
                }
            }
        }
        return cost;
    }
};
