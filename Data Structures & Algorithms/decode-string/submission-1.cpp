class Solution {
public:
    string decodeString(string s) {
        vector<string> stk;

        for(const char c: s) {
            if (c != ']') {
                stk.push_back(string(1, c));
            }
            else {
                string comp = "";
                while (stk.back() != "[") {
                    comp = stk.back() + comp;
                    stk.pop_back();
                }
                stk.pop_back(); // pop '['
                string numStr = "";
                while (!stk.empty() && isdigit(stk.back()[0])) {
                    numStr = stk.back() + numStr;
                    stk.pop_back();
                }
                int num = stoi(numStr);

                string substring = "";
                while (num > 0) {
                    substring += comp;
                    --num;
                }
                stk.push_back(substring);
            }
        }

        string ans = "";
        for(int i = 0; i < stk.size(); ++i) {
            ans += stk[i];
        }

        return ans;
    }
};