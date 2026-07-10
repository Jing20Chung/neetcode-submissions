class Solution {
public:
    int characterReplacement(string s, int k) {
        // at most k different char in the window
        // how to know the dominate char? by maxCount?
        vector<int> counts(26);
        const int n = s.size();
        int maxLen = 0;
        int maxCount = 0;
        int L = 0;
        for(int R = 0; R < n; ++R) {
            const int c = s[R] - 'A';
            maxCount = max(maxCount, ++counts[c]);
            while ((R - L + 1) - maxCount > k) {
                --counts[s[L++] - 'A'];
            }

            maxLen = max(maxLen, R - L + 1);
        }
        return maxLen;
    }
};
