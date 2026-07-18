class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> indegree(m, vector<int>(n, 0));
        const int dr[4] = {1, -1, 0, 0};
        const int dc[4] = {0, 0, 1, -1};
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                for(int i = 0; i < 4; ++i) {
                    int newR = r + dr[i];
                    int newC = c + dc[i];
                    if (newR >= m || newR < 0 || newC >= n || newC < 0 || matrix[r][c] <= matrix[newR][newC]) continue;
                    indegree[r][c]++;
                }
            }
        }

        queue<tuple<int, int, int>> q;
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if (indegree[r][c] == 0) {
                    q.push({r, c, 1});
                }
            }
        }

        int maxLen = 1;
        while (!q.empty()) {
            auto[r, c, len] = q.front();
            maxLen = max(maxLen, len);
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int newR = r + dr[i];
                int newC = c + dc[i];
                if (newR >= m || newR < 0 || newC >= n || newC < 0 || matrix[r][c] >= matrix[newR][newC]) continue;
                indegree[newR][newC]--;
                if (indegree[newR][newC] == 0) {
                    q.push({newR, newC, len + 1});
                }
            }
        }

        return maxLen;
    }
};
