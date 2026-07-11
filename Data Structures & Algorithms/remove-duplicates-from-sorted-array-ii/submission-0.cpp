class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = std::ssize(nums);
        if (n <= 2) return n;

        int L = 2;
        for(int R = 2; R < n; ++R) {
            if (nums[L - 2] != nums[R]) {
                nums[L] = nums[R];
                L++;
            }
        }
        return L;
    }
};