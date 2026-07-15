class Solution {
    int totalSum, targetSum;
    vector<vector<int>> dp; // i, curSum = ans
public:
    int lastStoneWeightII(vector<int>& stones) {
        totalSum = accumulate(stones.begin(), stones.end(), 0);
        targetSum = (totalSum + 1) / 2;
        dp = vector<vector<int>>(stones.size(), vector<int>(targetSum + 1, -1));
        return dfs(0, 0, stones);
    }

    int dfs(int i, int curSum, vector<int>& stones) {
        if (curSum >= targetSum || i == stones.size()) {
            return abs(curSum - (totalSum - curSum));
        }
        if (dp[i][curSum] != -1) return dp[i][curSum];

        int res = min(dfs(i + 1, curSum, stones), dfs(i + 1, curSum + stones[i], stones));
        dp[i][curSum] = res;
        return res;
    } 
};