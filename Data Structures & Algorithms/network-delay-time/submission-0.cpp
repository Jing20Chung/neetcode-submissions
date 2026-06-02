class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto time: times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k}); // time, node

        while(!pq.empty()) {
            auto [curTime, node] = pq.top();
            pq.pop();

            if (dist[node] < curTime) continue;

            for(auto [nextNode, travelTime]: adj[node]) {
                if (dist[nextNode] > curTime + travelTime) {
                    dist[nextNode] = curTime + travelTime;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;

            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
