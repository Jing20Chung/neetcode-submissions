class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> mp(numCourses);
        for(auto pre: prerequisites) {
            indegree[pre[0]]++;
            mp[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i); // courses that don't have prerequisit
            }
        }

        int finished = 0;

        while(!q.empty()) {
            int course = q.front();
            q.pop();
            finished++;
            for(int nei: mp[course]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        return finished == numCourses;
    }
};
