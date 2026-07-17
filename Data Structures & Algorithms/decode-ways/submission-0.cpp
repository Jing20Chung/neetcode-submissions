class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int prev = 1;
        int prev2 = 0;
        for(int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                prev2 = prev;
                prev = 0;
            }
            else {
                int tmp = prev;
                if ((i + 1 < n) && (s[i] == '1' || 
                                    (s[i] == '2' && s[i + 1] < '7'))) {
                                        tmp += prev2;
                                    }
                prev2 = prev;
                prev = tmp;
            }
        }
        return prev;
    }
};
