class Solution {
public:
    double myPow(double x, int n) {
        double ans = cal(x, abs(n));
        return n > 0? ans: 1.0 / ans;
    }

    double cal(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        double result = cal(x, n / 2);
        result = result * result;
        return (n % 2 == 1)? result * x: result;
    }
};
