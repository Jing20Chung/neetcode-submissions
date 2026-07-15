class Solution {
    vector<vector<int>> counts;
    vector<vector<vector<int>>> dp;
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 0-1 knapsack
        // num of possible 0's and 1's
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(string& str: strs) {
            int zCnt = 0;
            int oneCnt = 0;
            for(char c: str) {
                if (c == '0') zCnt++;
                else oneCnt++;
            }

            for(int j = m; j >= zCnt; --j) { // we only need to update the number between m ~ zCnt because we only care about those possible solutions with enough space for this string (it has zCnt of 0's)
                for(int k = n; k >= oneCnt; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - zCnt][k - oneCnt] + 1);
                }
            }
        }
        return dp[m][n];
    }
};