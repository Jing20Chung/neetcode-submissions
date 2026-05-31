class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& pre: prerequisites) {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> res;
        res.reserve(numCourses);
        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int course = q.front();
            q.pop();
            res.push_back(course);
            for(auto& nei: adj[course]) {
                indegree[nei]--;
                if(indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if (res.size() == numCourses) {
            return res;
        }
        else {
            return {};
        }
    }
};
