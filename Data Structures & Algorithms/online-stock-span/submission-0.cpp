class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while (!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price, span});
        return span;
    }

    stack<pair<int, int>> stk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 // prefix sum?
 // but the price is growing
 // if every time next got called, I trace backward to find the span
 // it is O(N).
 // is it possible to achieve O(1)?