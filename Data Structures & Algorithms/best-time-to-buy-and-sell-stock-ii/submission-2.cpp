class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n + 1, 0);
        vector<int> sell(n + 1, 0);

        for(int i = n - 1; i >= 0; --i) {
            int price = prices[i];
            buy[i] = max(buy[i + 1], -price + sell[i + 1]);
            sell[i] = max(sell[i + 1], price + buy[i + 1]);
        }
        return buy[0];
    }
};