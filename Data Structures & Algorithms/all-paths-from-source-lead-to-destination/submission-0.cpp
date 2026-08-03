class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> path(n, 0);
        return findPath(source, destination, path, adj);
    }

    bool findPath(int cur, const int destination, vector<int>& path, vector<vector<int>>& adj) {
        if (path[cur] != 0) return path[cur] == 2; // fully explored
        if (adj[cur].size() == 0) return cur == destination; // only destination should be the dead end

        path[cur] = 1; // exploring/ seen
        for(int nei: adj[cur]) {
            if (!findPath(nei, destination, path, adj)) {
                return false;
            }
        }
        path[cur] = 2; // explored
        return true;
    }
};
