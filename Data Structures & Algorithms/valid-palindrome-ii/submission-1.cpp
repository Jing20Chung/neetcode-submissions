class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                ++l;
                --r;
            }
            else {
                return isPalindrome(l + 1, r, s) || isPalindrome(l, r - 1, s);
            }
        }
        return true;
    }

    bool isPalindrome(int l, int r, string& s) {
        while(l < r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};