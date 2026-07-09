class Solution {
private:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = l + rand() % (r - l + 1);
        int pVal = nums[pivot];
        int s = l;
        swap(nums[pivot], nums[r]);
        for(int curr = l; curr < r; curr++) {
            if (nums[curr] < pVal) {
                swap(nums[curr], nums[s]);
                s++;
            }
        }
        swap(nums[s], nums[r]);
        return s;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;
        int l = 0, r = n - 1;
        while(l <= r) {
            int result = partition(nums, l, r);
            if (result == target) return nums[target];
            else if (result < target) {
                l = result + 1;
            }
            else {
                r = result - 1;
            }
        }
        return -1;
    }
};
