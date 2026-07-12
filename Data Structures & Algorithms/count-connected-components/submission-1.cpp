class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int count = n; // initially, there are n components if each node is not connected.

        for(const auto& edge: edges) {
            int root1 = findRoot(edge[0], parent);
            int root2 = findRoot(edge[1], parent);

            if (root1 != root2) { // combine these two nodes into one component
                parent[root1] = root2;
                count--;
            }
        }
        return count;
    }

    int findRoot(int node, vector<int>& parent) {
        if (parent[node] == node) return node;
        return parent[node] = findRoot(parent[node], parent);
    }
};
