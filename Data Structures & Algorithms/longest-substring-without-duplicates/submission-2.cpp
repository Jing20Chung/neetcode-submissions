class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> indice(256, -1);
        const int n = s.size();
        int L = 0;
        int maxLen = 0;
        for(int R = 0; R < n; ++R) {
            const uint8_t curChar = static_cast<uint8_t>(s[R]);
            if (indice[curChar] != -1) {
                L = max(L, indice[curChar] + 1);
            }
            maxLen = max(R - L + 1, maxLen);
            indice[curChar] = R;
        }
        return maxLen;
    }
};
