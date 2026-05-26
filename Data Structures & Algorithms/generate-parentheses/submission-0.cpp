class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        solve(0, 0, n, res, cur);
        return res;
    }

private:
    void solve(int open, int close, int n, vector<string>& res, string& cur) {
        if(open == close && open == n) {
            res.push_back(cur);
            return;
        }

        if (open < n) {
            cur += '(';
            solve(open + 1, close, n, res, cur);
            cur.pop_back();
        }

        if (open > close) {
            cur += ')';
            solve(open, close + 1, n, res, cur);
            cur.pop_back();
        }
    }
};
