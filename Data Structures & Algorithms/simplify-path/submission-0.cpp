class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string comp = "";

        for(int i = 0; i < path.size(); ++i) {
            char c = path[i];

            if (c == '/') {
                if (comp != "") {
                    if (comp == "..") {
                        if (!stk.empty()) {
                            stk.pop_back();
                        }
                    }
                    else if (comp != ".") {
                        stk.push_back(comp);
                    }
                    comp = "";
                }
            }
            else {
                comp += c;
            }
        }

        if (!comp.empty()) {
            if (comp == "..") stk.pop_back();
            else if (comp != ".") stk.push_back(comp);
        }

        string ans = "/";
        for(int i = 0; i < (int)stk.size(); ++i) {
            ans += stk[i];
            if (i < (int) stk.size() - 1) ans += "/";
        }
        return ans;
    }
};