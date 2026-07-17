class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> path(n);
        for(auto flight: flights) {
            path[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<vector<int>> costs(n, vector<int>(k + 2, INT_MAX));
        costs[src][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        // k is the maximum number of stops you can make (not including src and dst)
        pq.push({0, src, 0}); // cost, curStop, steps
        while(!pq.empty()) {
            auto[curCost, curStop, curSteps] = pq.top();
            pq.pop();
            if (curCost > costs[curStop][curSteps]) continue;
            if (curStop == dst) return curCost;

            for(auto[nei, price]: path[curStop]) {
                int nextCost = curCost + price;
                int nextSteps = curSteps + 1;
                if (nextSteps > k + 1 || nextCost >= costs[nei][nextSteps]) continue;
                costs[nei][nextSteps] = nextCost;
                pq.push({nextCost, nei, nextSteps});
            }
        }
        return -1;
    }
};
