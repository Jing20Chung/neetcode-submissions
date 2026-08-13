class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // the answer is in the range [1, n + 1] where n is the length of the nums array
        // because if the array is continous numbers [1,2,3], then the first missing positive number
        // will be 4, which is n + 1
        // otherwise, there must be some number missing in the array within range of [1, n]

        // use the origin array as the auxiliary space
        // use +/- sign as the number within [1, n] exists in the array
        // we kill negatives and the number which is greater than n by setting them 
        // as 1s

        // because we use 1s as indicators, we also need to record if 
        // 1 is actually exists in the array
        int n = nums.size();
        bool hasOne = false;
        for(int i = 0; i < n; ++i) {
            if (nums[i] == 1) hasOne = true;
            else if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }

        // the reason to use 1 to replace negatives and those greater
        // than n is because we can't allow those values to 
        // affect the flag we use in the following logic,
        // and 1 can also be used to easily set to negative
        // when somewhere in the array has the index of this
        // value and we need to set this value to be negative

        if (!hasOne) return 1;
        // next, use the index of the array to indicate whether the
        // number of that index exists in the array
        // index 2's number's sign represents whether number 2 exists
        // in the array
        // and use index 0 to represent if n exists in the array since
        // 0 is not a valid answer and already got transform into 1s 
        // in previous steps
        for(int i = 0; i < n; ++i) {
            int val = abs(nums[i]);
            if (val == n) {
                nums[0] = -abs(nums[0]);
            }
            else {
                nums[val] = -abs(nums[val]);
            }
        }

        for(int i = 1; i < n; ++i) {
            if (nums[i] > 0) {
                return i;
            }
        }
        if (nums[0] > 0) return n;
        return n + 1;
    }
};