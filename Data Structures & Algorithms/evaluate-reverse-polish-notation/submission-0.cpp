class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        for(const string& token: tokens) {
            if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
                long long num2 = stk.top();
                stk.pop();
                long long num1 = stk.top();
                stk.pop();
                if (token[0] == '+') stk.push(num1 + num2);
                else if (token[0] == '-') stk.push(num1 - num2);
                else if (token[0] == '*') stk.push(num1 * num2);
                else if (token[0] == '/') stk.push(num1 / num2);
            }
            else {
                stk.push(stol(token));
            }
        }
        return static_cast<int>(stk.top());
    }
};
