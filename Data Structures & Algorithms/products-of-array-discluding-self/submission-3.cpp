class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = std::ssize(nums);
        vector<int> output(n, 1);
        for(int i = 1; i < n; ++i) {
            output[i] = output[i - 1] * nums[i - 1];
        }

        int rightProduct = nums[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            output[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return output;
    }
};
