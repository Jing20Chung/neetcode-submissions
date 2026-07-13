class Solution {
    const vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(int i, const string& digits, string& curr, vector<string>& ans) {
        if (i >= digits.size()) {
            ans.push_back(curr);
            return;
        }
        int digit = digits[i] - '0';
        for(const char c: dict[digit]) {
            curr.push_back(c);
            solve(i + 1, digits, curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        string curr;
        curr.reserve(digits.size());
        solve(0, digits, curr, ans);
        return ans;
    }
};
