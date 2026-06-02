class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for(const auto& edge: edges) {
            int root1 = find(edge[0], parent);
            int root2 = find(edge[1], parent);

            if (root1 != root2) {
                parent[root2] = root1;
            }
            else {
                return vector<int>{edge[0], edge[1]};
            }
        }

        return {};
    }

    int find(int node, vector<int>& parent) {
        if (node == parent[node]) return node;
        while(node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }
};
