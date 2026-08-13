class Solution {
public:
    bool validPalindrome(string s) {
        return solve(s, 0, s.size() - 1, false);
    }

    bool solve(string& s, int l, int r, bool skipped) {
        if (l >= r) return true;
        if (s[l] != s[r] && skipped) return false;
        if (s[l] == s[r]) return solve(s, l + 1, r - 1, skipped);
        else return (solve(s, l + 1, r, true) || solve(s, l, r - 1, true));
    }
};