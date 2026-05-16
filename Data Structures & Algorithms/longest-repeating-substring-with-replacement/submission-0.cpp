class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int curMax = 0;
        int maxCount = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxCount = max(maxCount, count[s[r] - 'A']);

            while ((r - l + 1) - maxCount > k) {
                count[s[l] - 'A']--;
                l++;
            }

            curMax = max(curMax, r - l + 1);
        }
        return curMax;
    }
};
