class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX);

        int path = 0;
        int node = 0;
        int res = 0;
        while(path < n - 1) {
            visited[node] = true;
            int nextNode = -1;
            for(int i = 0; i < n; i++) {
                if (visited[i]) continue;
                int curDist = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);
                dist[i] = min(dist[i], curDist);
                if (nextNode == -1 || dist[i] < dist[nextNode]) {
                    nextNode = i;
                }
            }
            path++;
            res += dist[nextNode];
            node = nextNode;
        }

        return res;
    }
};
