class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) return grid[0][0];

        // each round, check the cell in queue
        // to see if the water level at time t
        // is greater or equal to the cell
        // if it is, pop it and add its neighbor
        // into the queue.

        // I need a min heap to get the lowest height
        // cell every time I check the water level
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        
        // I need to memorize which cell has been visited
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // four directions
        const int dr[4] = {1, -1, 0, 0};
        const int dc[4] = {0, 0, 1, -1};
        
        // start from (0, 0)
        minHeap.push({grid[0][0], 0, 0}); // height, r, c
        visited[0][0] = true;

        while(!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int time = top[0];
            int r = top[1];
            int c = top[2];

            for(int i = 0; i < 4; ++i) {
                int newR = r + dr[i];
                int newC = c + dc[i];

                if (newR == m - 1 && newC == n - 1) {
                    return max(time, grid[newR][newC]);
                }

                if (newR >= m || newR < 0 || newC >= n || newC < 0 || visited[newR][newC]) continue;

                minHeap.push({max(time, grid[newR][newC]), newR, newC});
                visited[newR][newC] = true;
            }
        }
        return -1;
    }
};
