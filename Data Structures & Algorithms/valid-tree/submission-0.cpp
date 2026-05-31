class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> seen(n, false);
        vector<vector<int>> path(n);

        if(edges.size() != n - 1) return false;

        for(auto& edge: edges) {
            path[edge[0]].push_back(edge[1]);
            path[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        q.push(0);
        seen[0] = true;
        int cnt = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            cnt++;
            for(const int& nei: path[cur]) {
                if (!seen[nei]) {
                    seen[nei] = true;
                    q.push(nei);
                }
            }
        }

        return cnt == n;
    }
};
