class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(), l = 0, r = n - 1;
        while (l < r) {
            while(l < r && !std::isalnum(static_cast<unsigned char>(s[l]))) l++;
            while(l < r && !std::isalnum(static_cast<unsigned char>(s[r]))) r--;
            
            if (toupper(static_cast<unsigned char>(s[l])) != toupper(static_cast<unsigned char>(s[r]))) return false;
            l++;
            r--;
        }
        return true;
    }
};
