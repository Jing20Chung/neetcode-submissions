class Solution {
public:
    int search(vector<int>& nums, int target) {
        // logn time -> binary search
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (r + l) / 2;
            int val = nums[mid];
            if (val < target) {
                l = mid + 1;
            }
            else if (val > target) {
                r = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};
