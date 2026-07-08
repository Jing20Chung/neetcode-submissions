class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> score;
        for(string op: operations) {
            if (op == "+") {
                int prev = score.top();
                score.pop();
                int prev2 = score.top();
                score.push(prev);
                score.push(prev + prev2);
            }
            else if (op == "D") {
                score.push(score.top() * 2); 
            }
            else if (op == "C") {
                score.pop();
            }
            else {
                score.push(stoi(op));
            }
        }

        int ans = 0;
        while(!score.empty()) {
            ans += score.top();
            score.pop();
        }
        return ans;
    }
};