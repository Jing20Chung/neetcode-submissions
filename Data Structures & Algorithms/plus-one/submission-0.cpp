class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int sum = digits[n - 1] + 1;
        int carry = sum / 10;
        digits[n - 1] = sum % 10;

        for(int i = digits.size() - 2; i >= 0; --i) {
            if (carry == 0) break;
            else {
                digits[i] += carry;
                carry = digits[i] / 10;
                digits[i] = digits[i] % 10;
            } 
        }
        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
