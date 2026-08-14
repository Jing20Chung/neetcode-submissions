class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        int l = 1, r = x;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long pow = (long long)mid * mid;
            if (pow <= x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return r;
    }
};