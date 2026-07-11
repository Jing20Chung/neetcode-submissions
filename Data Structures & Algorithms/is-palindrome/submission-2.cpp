class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(static_cast<unsigned char>(s[l]))) l++;
            while (l < r && !isalnum(static_cast<unsigned char>(s[r]))) r--;
            if (toupper(static_cast<unsigned char>(s[l])) != toupper(static_cast<unsigned char>(s[r]))) return false;
            l++;
            r--;
        }
        return true;
    }
};
