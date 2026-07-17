class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    count++;
                    --l;
                    ++r;
                }
                else break;
            }

            l = i;
            r = i + 1;
            while(l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    count++;
                    --l;
                    ++r;
                }
                else break;
            }
        }
        return count;
    }
};
