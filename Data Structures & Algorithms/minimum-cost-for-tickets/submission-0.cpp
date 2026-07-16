class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        vector<pair<int, int>> passes = {{1, costs[0]}, {7, costs[1]}, {30, costs[2]}};
        for(int i = 0; i < n; ++i) {
            for(auto[len, cost]: passes) {
                int j = i;
                while(j >= 0 && days[j] >= days[i] - len + 1) --j;
                dp[i + 1] = min(dp[i + 1], dp[j + 1] + cost);
            }
        }

        return dp[n];
    }
};