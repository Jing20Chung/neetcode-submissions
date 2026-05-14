class Solution {
public:

    string encode(vector<string>& strs) {
        string toSend;
        for(auto const& str: strs) {
            toSend += to_string(str.size()) + "#" + str;
        }
        return toSend;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;

            // make sure digits and '#' in the original string can be decoded correctly.
            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }

        return result;
    }
};
