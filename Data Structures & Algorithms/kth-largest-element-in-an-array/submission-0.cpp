class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int targetIdx = n - k;
        int l = 0, r = n - 1;
        while (l <= r) {
            int res = partition(nums, l, r);
            if (res == targetIdx) return nums[res];
            else if (res < targetIdx) l = res + 1;
            else r = res - 1;
        }
        return -1;
    }

private:
    int partition(vector<int>& nums, int start, int end) {
        int randIdx = start + rand() % (end - start + 1);
        int pivotVal = nums[randIdx];
        swap(nums[randIdx], nums[end]);
        int l = start;
        for (int i = start; i < end; i++) {
            if(nums[i] < pivotVal) {
                swap(nums[i], nums[l]);
                l++;
            }
        }
        swap(nums[l], nums[end]);
        return l;
    }
};
