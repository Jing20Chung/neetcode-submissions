class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> costs(n, INT_MAX);
        costs[src] = 0;

        for(int i = 0; i < k + 1; ++i) {
            vector<int> tmp = costs;
            for(auto flight: flights) {
                int s = flight[0];
                int d = flight[1];
                int w = flight[2];

                if (costs[s] == INT_MAX) continue;

                if (tmp[d] > costs[s] + w) {
                    tmp[d] = costs[s] + w;
                }
            }
            costs = tmp;
        }

        return costs[dst] == INT_MAX? -1: costs[dst];
    }
};
