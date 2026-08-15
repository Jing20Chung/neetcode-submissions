class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            adj[A].push_back({A, 1.0});
            adj[B].push_back({B, 1.0});
            adj[A].push_back({B, val});
            adj[B].push_back({A, 1.0/val});
        }
        vector<double> ans;
        for(auto query: queries) {
            string src = query[0];
            string dst = query[1];

            if (!adj.contains(src) || !adj.contains(dst)) {
                ans.push_back(-1.0);
                continue;
            }
            else {
                double w = solve(src, dst, adj);
                ans.push_back(w);
                adj[src].push_back({dst, w});
                adj[dst].push_back({src, 1.0/w});
            }
        }
        return ans;
    }

    double solve(string& src, string& dst, unordered_map<string, vector<pair<string, double>>>& adj) {
        unordered_set<string> seen;
        queue<pair<string, double>> q;
        q.push({src, 1.0});
        while (!q.empty()) {
            auto[cur, w] = q.front();
            q.pop();
            if (cur == dst) return w;
            for(auto[nei, nei_w]: adj[cur]) {
                if (seen.count(nei)) continue;
                else {
                    seen.insert(nei);
                    q.push({nei, nei_w * w});
                }
            }
        }
        return -1.0;        
    }
};