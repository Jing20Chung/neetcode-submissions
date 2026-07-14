class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // [1] -> [0]
        // 0's index
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> path(numCourses);
        for(const auto& pre: prerequisites) {
            path[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        int finished = 0;
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int course = q.front(); q.pop();
            finished++;
            ans.push_back(course);
            for(int nei: path[course]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        return finished == numCourses? ans: vector<int>();
    }
};
