class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        queue<pair<int, int>> q;
        priority_queue<int> maxHeap;

        vector<int> count(26, 0);

        for(const char& task: tasks) {
            count[task-'A']++;
        }

        for(const int& freq: count) {
            if (freq != 0) {
                maxHeap.push(freq);
            }
        }

        int time = 0;
        while (!maxHeap.empty() || !q.empty()) {
            time++;
            
            if (!maxHeap.empty()) {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) q.push({cnt, time + n});
            }
            else {
                time = q.front().second;
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
