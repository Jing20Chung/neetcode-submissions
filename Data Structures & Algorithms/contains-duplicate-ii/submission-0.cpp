class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k < 1 || nums.size() < 2) return false;

        unordered_set<int> seen;
        for(int R = 0; R < nums.size(); R++) {
            if (R > k) {
                seen.erase(nums[R - k - 1]);
            }
            if (seen.count(nums[R])) return true;
            seen.insert(nums[R]);
        }
        return false;
    }
};