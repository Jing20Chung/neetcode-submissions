/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int guessResult = guess(mid);
            if (guessResult < 0) { // too big
                hi = mid - 1;
            }
            else if (guessResult > 0) { // too small
                lo = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};