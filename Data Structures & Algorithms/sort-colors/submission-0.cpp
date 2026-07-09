class Solution {
public:
    void sortColors(vector<int>& nums) {
        // bucket sort
        int counts[3] = {0, 0, 0};

        for(int num: nums) {
            counts[num]++;
        }

        int i = 0;
        for(int j = 0; j < 3; j++) {
            for(int n = counts[j]; n > 0; n--) {
                nums[i] = j;
                i++;
            }
        }
    }
};