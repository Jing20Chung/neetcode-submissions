class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> curr(n + 1, 0);
        vector<int> prev(n + 1, 0);

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    curr[j] = prev[j + 1] + 1;
                }
                else {
                    curr[j] = max(prev[j], curr[j + 1]);
                }
            }
            swap(curr, prev);
        }
        return prev[0];
    }
};
