class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> count(128, 0);
        vector<int> window(128, 0);
        int l = 0;
        int start = 0;
        int have = 0, need = 0;
        int minLen = INT_MAX;

        for(const char& c: t) {
            if (count[c] == 0) need++;
            count[c]++;
        }


        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (count[c] > 0 && window[c] == count[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < minLen) {
                    minLen = (r - l + 1);
                    start = l;
                }

                char leftChar = s[l];
                window[leftChar]--;
                if (count[leftChar] > 0 && window[leftChar] < count[leftChar]) {
                    have--;
                }
                l++;
            }
        }

        return minLen == INT_MAX? "": s.substr(start, minLen);
    }
};
