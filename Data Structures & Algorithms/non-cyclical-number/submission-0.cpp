class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = operation(n);
        while (slow != fast) {
            slow = operation(slow);
            fast = operation(fast);
            fast = operation(fast);
        }

        return fast == 1;
    }

    int operation(int n) {
        int result = 0;
        while(n != 0) {
            int digit = n % 10;
            result += digit * digit;
            n /= 10;
        }
        return result;
    }
};
