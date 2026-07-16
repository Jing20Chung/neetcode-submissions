class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return dfs(0, 0, word1, word2, dp);
    }

    int dfs(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if (i == word1.size()) return word2.size() - j; // insert all remaining word2's letters
        if (j == word2.size()) return word1.size() - i; // remove all remaining word1's letters
        if (dp[i][j] != -1) return dp[i][j];

        int res = 0;
        if(word1[i] == word2[j]) {
            res = dfs(i + 1, j + 1, word1, word2, dp);
        }
        else {
            res = 1 + min(dfs(i, j + 1, word1, word2, dp), // insert one letter to word1 to match word2
                            min(dfs(i + 1, j, word1, word2, dp), // delete one letter of word1
                                dfs(i + 1, j + 1, word1, word2, dp)) // replace one letter of word1
                            );
        }

        dp[i][j] = res;
        return res;
    }
};
