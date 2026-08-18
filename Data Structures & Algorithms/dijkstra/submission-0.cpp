class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [w, cur] = pq.top();
            pq.pop();
            if (dist[cur] < w) continue;
            dist[cur] = w;
            for(auto [nei, nei_w]: adj[cur]) {
                pq.push({w + nei_w, nei});
            }
        }

        unordered_map<int, int> ans;
        for(int i = 0; i < n; ++i) {
            if (dist[i] == INT_MAX) {
                ans[i] = -1;
            }
            else {
                ans[i] = dist[i];
            }
        }

        return ans;
    }
};
