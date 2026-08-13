class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int vote = 1;

        for(int i = 1; i < nums.size(); ++i) {
            if (nums[i] != candidate) {
                if (vote == 1) {
                    candidate = nums[i];
                }
                else {
                    --vote;
                }
            }
            else {
                ++vote;
            }
        }
        return candidate;
    }
};