class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;
        int n = word1.size();
        int m = word2.size();

        while(i < n || j < m) {
            if (i < n) {
                result += word1[i++];
            }
            if (j < m) {
                result += word2[j++];
            }
        }
        return result;
    }
};