class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, 0);
        int cnt = n;
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto& edge: edges) {
            int root1 = find(parent, edge[0]);
            int root2 = find(parent, edge[1]);

            if(root1 != root2) {
                parent[root2] = root1;
                cnt--;
            }
        }
        return cnt;
    }

    int find(vector<int>& parent, int i) {
        if (parent[i] == i) return i;

        return parent[i] = find(parent, parent[i]);
    }
};
