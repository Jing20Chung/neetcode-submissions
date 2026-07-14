class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // [1] -> [0] ----> [0] -> [1]
        // 0's index
        vector<vector<int>> path(numCourses);
        for(const auto& pre: prerequisites) {
            path[pre[0]].push_back(pre[1]);
        }

        vector<bool> inPath(numCourses, false);
        vector<bool> visited(numCourses, false);
        vector<int> ans;
        for(int i = 0; i < numCourses; ++i) {
            if (visited[i]) continue;
            if (!dfs(i, visited, inPath, ans, path)) {
                return {};
            }
        }

        return ans;
    }

    bool dfs(int course, vector<bool>& visited, vector<bool>& inPath, vector<int>& ans, const vector<vector<int>>& path) {
        inPath[course] = true;
        visited[course] = true;
        for(int nei: path[course]) {
            if (inPath[nei]) return false;
            else if (!visited[nei] && !dfs(nei, visited, inPath, ans, path)) return false;
        }
        ans.push_back(course);
        inPath[course] = false;
        return true;
    }
};
