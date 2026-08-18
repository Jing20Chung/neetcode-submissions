class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        int remain = n;
        vector<bool> seen(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //w, node
        pq.push({0, 0});
        int res = 0;
        while(!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();
            if (seen[node]) continue;
            seen[node] = true;
            res += weight;
            --remain;
            for(auto [nei, w]: adj[node]) {
                if (!seen[nei]) {
                    pq.push({w, nei});
                }
            }
        }
        return remain == 0? res: -1;
    }
};

