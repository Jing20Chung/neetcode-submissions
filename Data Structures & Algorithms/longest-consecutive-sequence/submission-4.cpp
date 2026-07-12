class UnionFind {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
public:
    void insert(int node) {
        if (!parent.contains(node)) {
            parent[node] = node;
            rank[node] = 1;
        }
    }

    bool contains(int node) {
        return parent.contains(node);
    }

    int unionNodes(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 != root2) {
            parent[root1] = root2;
            rank[root2] += rank[root1];
            return rank[root2];
        }
        else return 0;
    }

    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxLen = 1;
        UnionFind uf;
        for(int num: nums) {
            uf.insert(num);
        }

        for(int num: nums) {
            if (uf.contains(num + 1)) {
                maxLen = max(maxLen, uf.unionNodes(num, num + 1));
            }
        }
        return maxLen;
    }
};
