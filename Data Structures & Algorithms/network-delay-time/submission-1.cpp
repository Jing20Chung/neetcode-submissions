class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if (n == 0 || k > n || k <= 0) return -1;

        vector<vector<pair<int, int>>> path(n + 1);
        for(const auto& time: times) {
            path[time[0]].push_back({time[1], time[2]});
        }

        int remainNodes = n;
        vector<bool> visited(n + 1, false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});

        int maxTime = 0;
        while(!minHeap.empty()) {
            auto[curTime, node] = minHeap.top();
            minHeap.pop();

            if(visited[node]) continue;

            maxTime = max(maxTime, curTime);
            visited[node] = true;
            remainNodes--;
            
            if (remainNodes == 0) break;

            for(const auto&[nei, time]: path[node]) {
                if (visited[nei]) continue;
                minHeap.push({curTime + time, nei});
            }
        }
        return remainNodes == 0? maxTime: -1;
    }
};
