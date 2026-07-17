class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(helper(0, n - 2, nums), helper(1, n - 1, nums));
    }

    int helper(int start, int end, vector<int>& nums) {
        int prev2 = 0;
        int prev = 0;
        for(int i = start; i <= end; ++i) {
            int tmp = max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = tmp;
        }
        return prev;
    }
};
