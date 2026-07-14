class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        rank.resize(n, 1);
    }

    int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    bool unionNode(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 == root2) return false;

        int rank1 = rank[root1];
        int rank2 = rank[root2];

        if (rank1 > rank2) {
            parent[root1] = root2;
        }
        else if (rank1 < rank2) {
            parent[root2] = root1;
        }
        else {
            parent[root1] = root2;
            rank[root2] += rank[root1];
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // 0's index
        // undirect graph with weighted edge
        for(int i = 0; i < edges.size(); ++i) {
            edges[i] = {edges[i][2], edges[i][0], edges[i][1], i};
        }
        sort(edges.begin(), edges.end());

        int mst_w = 0;
        UnionFind uf(n);
        for(int i = 0; i < edges.size(); ++i) {
            int v1 = edges[i][1];
            int v2 = edges[i][2];
            int w = edges[i][0];
            int e_idx = edges[i][3];
            if (uf.unionNode(v1, v2)) {
                mst_w += w;
            }
        }

        vector<int> critical;
        vector<int> psuCritical;

        for(int i = 0; i < edges.size(); ++i) {
            int v1 = edges[i][1];
            int v2 = edges[i][2];
            int w = edges[i][0];
            int e_idx = edges[i][3];

            // find critical edge
            UnionFind uf(n);
            int weight = 0;
            int edgeCount = 0;
            for(int j = 0; j < edges.size(); ++j) {
                // exclude edge[i]
                if (i == j) continue;
                int jv1 = edges[j][1];
                int jv2 = edges[j][2];
                int jw = edges[j][0];
                if (uf.unionNode(jv1, jv2)) {
                    weight += jw;
                    edgeCount++;
                }
            }

            if (weight > mst_w || edgeCount < n - 1) {
                critical.push_back(e_idx);
            }
            else {
                // find pseudo critical edge
                UnionFind uf2(n);
                weight = w;
                uf2.unionNode(v1, v2);
                for(int j = 0; j < edges.size(); ++j) {
                    // edge[i] already included
                    if (i == j) continue;
                    int jv1 = edges[j][1];
                    int jv2 = edges[j][2];
                    int jw = edges[j][0];
                    if (uf2.unionNode(jv1, jv2)) {
                        weight += jw;
                    }
                }
                if (weight == mst_w) {
                    psuCritical.push_back(e_idx);
                }
            }
        }
        vector<vector<int>> res;
        res.push_back(critical);
        res.push_back(psuCritical);
        return res;
    }
};