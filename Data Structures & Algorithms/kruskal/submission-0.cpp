class UnionFind {
public:
    UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
        }
        rank = vector<int>(n, 1);
    }

    bool join(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y) return false;

        if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
            rank[root_x] += rank[root_y];
        }
        else {
            parent[root_x] = root_y;
            rank[root_y] += rank[root_x];
        }
        return true;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    vector<int> rank;
    vector<int> parent;
};

class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

        for(auto edge: edges) {
            minHeap.push({edge[2], edge[0], edge[1]});
        }

        UnionFind uf(n);
        int res = 0;
        int compCnt = n;
        while (!minHeap.empty()) {
            auto [w, x, y] = minHeap.top();
            minHeap.pop();

            if (uf.join(x, y)) {
                res += w;
                --compCnt;
            }
        }

        return compCnt == 1? res: -1;
    }
};
