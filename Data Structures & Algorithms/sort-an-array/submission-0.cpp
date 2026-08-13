class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans(nums.begin(), nums.end());
        sort(0, nums.size() - 1, ans);
        return ans;
    }

    void sort(int start, int end, vector<int>& nums) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        sort(start, mid, nums);
        sort(mid + 1, end, nums);

        vector<int> temp;
        temp.reserve(end - start + 1);
        int i = start, j = mid + 1;
        while(i <= mid || j <= end) {
            if (i > mid) {
                temp.push_back(nums[j++]);
            }
            else if (j > end) {
                temp.push_back(nums[i++]);
            }
            else {
                if (nums[i] <= nums[j]) {
                    temp.push_back(nums[i++]);
                }
                else {
                    temp.push_back(nums[j++]);
                }
            }
        }

        for(int k = start; k <= end; ++k) {
            nums[k] = temp[k - start];
        }
    }
};