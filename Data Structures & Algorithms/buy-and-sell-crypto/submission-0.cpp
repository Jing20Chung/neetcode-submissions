class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curLow = prices[0];
        int curMaxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < curLow) {
                curLow = prices[i];
            }
            else if (prices[i] > curLow){
                curMaxProfit = max(curMaxProfit, prices[i] - curLow);
            }
        }
        return curMaxProfit;
    }
};
