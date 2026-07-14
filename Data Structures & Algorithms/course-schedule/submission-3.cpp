class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // b -> a
        // [1] -> [0]
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
                q.push(i); // this course doesn't have any prerequisite
                finished++;
            }
        }
        
        while(!q.empty()) {
            int course = q.front();
            q.pop();

            for(int nei: path[course]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                    finished++;
                }
            }
        }

        return numCourses == finished;
    } 
};
