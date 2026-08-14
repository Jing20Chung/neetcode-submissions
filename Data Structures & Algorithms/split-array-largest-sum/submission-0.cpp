class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canSplit(nums, mid, k)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool canSplit(vector<int>& nums, int cap, int k) {
        int curSum = 0;
        int cnt = 1;
        for(int num: nums) {
            if (curSum + num > cap) {
                curSum = 0;
                cnt++;
                if (cnt > k) return false;
            }
            curSum += num;
        }
        return true;
    }
};