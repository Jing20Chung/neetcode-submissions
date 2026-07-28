class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for(int i = 1; i < strs.size(); i++) {
            for(int l = 0; l < prefix.size(); l++) {
                if (prefix[l] != strs[i][l]) {
                    prefix = prefix.substr(0, l);
                    break;
                }
            }
        }
        return prefix;
    }
};