class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        for(int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            if (lookup.find(num) != lookup.end()) {
                return {lookup[num], i};
            }
            lookup[nums[i]] = i;
        }
        return {};
    }
};
