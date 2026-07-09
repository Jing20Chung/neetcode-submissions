class Solution {
private:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = l + rand() % (r - l + 1);
        int pVal = nums[pivot];
        swap(nums[r], nums[pivot]);
        int s = l;
        while(l < r) {
            if (nums[l] < pVal) {
                swap(nums[s], nums[l]);
                s++;
            }
            l++;
        }
        swap(nums[s], nums[r]);
        return s;
    }
    int quickSelect(vector<int>& nums, int l, int r, int target) {
        if (l > r) return -1;
        while(true) {
            int result = partition(nums, l, r);
            if (target == result) {
                return nums[target];
            }
            else if (target > result) {
                l = result + 1;
            }
            else {
                r = result - 1;
            }
        }
        return -1;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
};
