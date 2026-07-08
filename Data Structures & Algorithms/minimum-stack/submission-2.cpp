class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minStk.empty() || val <= minStk.top()) {
            minStk.push(val);
        }
        stk.push(val);
    }
    
    void pop() {
        if (stk.top() == minStk.top()) {
            minStk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
private:
    stack<int> stk, minStk;
};
