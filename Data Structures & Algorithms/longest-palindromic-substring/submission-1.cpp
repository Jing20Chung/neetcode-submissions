class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> ans = {0, 0}; // index, length
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    int len = r - l + 1;
                    if (len > ans[1]) {
                        ans[0] = l;
                        ans[1] = len;
                    }
                    --l;
                    ++r;
                }
                else break;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    int len = r - l + 1;
                    if (len > ans[1]) {
                        ans[0] = l;
                        ans[1] = len;
                    }
                    --l;
                    ++r;
                }
                else break;
            }
        }
        return ans[1] == 0? "": s.substr(ans[0], ans[1]);
    }
};
