class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        if (edges.size() == 0) return {};

        int n = edges.size();
        vector<int> parent(n + 1, 0);
        // init parent to itself
        for(int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        for(vector<int> edge: edges) {
            int root1 = find(edge[0], parent);
            int root2 = find(edge[1], parent);
            if (root1 != root2) {
                parent[root1] = root2;
            }
            else {
                return {edge[0], edge[1]};
            }
        }
        return {};
    }

    int find(int node, vector<int>& parent) {
        if (parent[node] == node) {
            return node;
        }
        else {
            while (parent[node] != node) {
                parent[node] = parent[parent[node]];
                node = parent[node];
            }
            return node;
        }
    }
};
