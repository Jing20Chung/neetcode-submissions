class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        // 1
        // 2 1
        // 1 2
        // 3 1 2
        // 2 3 1
        // 1 2 3
        // 1 2
        // 4 1 2
        // 2 4 1
        // 1 2 4
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */