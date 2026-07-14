class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // pre[0] -> pre[1]
        vector<vector<int>> path(numCourses);
        vector<vector<bool>> preReMap(numCourses, vector<bool>(numCourses, false));
        for(const auto& pre: prerequisites) {
            path[pre[0]].push_back(pre[1]);
        }

        for(int i = 0; i < numCourses; ++i) {
            dfs(i, i, path, preReMap);
        }

        vector<bool> ans;
        for(const auto& q: queries) {
            ans.push_back(preReMap[q[0]][q[1]]);
        }
        return ans;
    }

    void dfs(int start, int curr, const vector<vector<int>>& path, vector<vector<bool>>& preReMap) {
        for(int nei: path[curr]) {
            if (!preReMap[start][nei]) {
                preReMap[start][nei] = true;
                dfs(start, nei, path, preReMap);
            }
        }
    }
};