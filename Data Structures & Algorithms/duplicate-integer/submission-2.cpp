class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num: nums) {
            if (!seen.insert(num).second) return true;
        }
        return false;
    }
};