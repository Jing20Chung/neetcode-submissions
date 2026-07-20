class Solution {
public:
    bool checkValidString(string s) {
        int maxLCnt = 0;
        int minLCnt = 0;

        for(char c: s) {
            if (c == '(') {
                maxLCnt++;
                minLCnt++;
            }
            else if (c == '*') {
                maxLCnt++;
                minLCnt--;
            }
            else { // ')'
                maxLCnt--;
                if (maxLCnt < 0) return false;
                minLCnt--;
            }

            minLCnt = max(minLCnt, 0); // minimum L count is never gonna be less than 0
        }

        return minLCnt == 0;
    }
};
