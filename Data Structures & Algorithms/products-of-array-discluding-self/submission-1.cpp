class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), l = 1, r = n - 2;
        vector<int> prefix = vector<int>(n, 1);
        vector<int> suffix = vector<int>(n, 1);
        vector<int> result = vector<int>(n, 1);

        while (l < n) {
            prefix[l] = prefix[l - 1] * nums[l - 1]; 
            suffix[r] = suffix[r + 1] * nums[r + 1];
            l++;
            r--;
        }
        
        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};
