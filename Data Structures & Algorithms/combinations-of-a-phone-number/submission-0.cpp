class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        const string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;
        string cur;
        dfs(0, digits, res, cur, mapping);
        return res;
    }
private:
    void dfs(int i, string& digits, vector<string>& res, string& cur, const string mp[]) {
        if(i >= digits.size()) {
            res.push_back(cur);
            return;
        }

        for(int j = 0; j < mp[digits[i] - '0'].size(); j++) {
            cur.push_back(mp[digits[i] - '0'][j]);
            dfs(i + 1, digits, res, cur, mp);
            cur.pop_back();
        }
    }
};
