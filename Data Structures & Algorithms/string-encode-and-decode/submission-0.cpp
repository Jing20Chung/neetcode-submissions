class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(string& str: strs) {
            int n = str.size();
            result += to_string(n) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int len = 0;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '#') {
                result.push_back(s.substr(i + 1, len));
                i += len;
                len = 0;
            }
            else {
                len *= 10;
                len += c - '0';
            }
        }
        return result;
    }
};
