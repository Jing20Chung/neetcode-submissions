class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // use maxHeap to run Dijkstra
        priority_queue<pair<double, int>> maxHeap;

        // build path map, use node as index
        vector<vector<pair<double, int>>> path(n);
        for(int i = 0; i < edges.size(); ++i) {
            path[edges[i][0]].push_back({succProb[i], edges[i][1]});
            path[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        // record prob
        vector<double> probOfNodes(n, 0.0);
        probOfNodes[start_node] = 1.0;

        // when visiting a node, update the node's prob using max(current prob * current path, prob[newNode])
        maxHeap.push({1.0, start_node});
        while(!maxHeap.empty()) {
            auto [prob, node] = maxHeap.top();
            maxHeap.pop();

            if (node == end_node) return prob;
            if (prob < probOfNodes[node]) continue;

            for(const auto& [probToNei, neiNode]: path[node]) {
                double newProb = prob * probToNei;
                if (newProb > probOfNodes[neiNode]) {
                    probOfNodes[neiNode] = newProb;
                    maxHeap.push({newProb, neiNode});
                }
            }
        }
        return 0.0;
    }
};