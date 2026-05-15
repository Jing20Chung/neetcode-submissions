class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        vector<int> lastPos(128, 0);
        int maxLen = 1;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            start = max(start, lastPos[s[i]]);
            maxLen = max(i - start + 1, maxLen);
            lastPos[s[i]] = i + 1;
        }
        return maxLen;
    }
};
