class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> copy;
        copy.reserve(nums.size() * 2);
        copy.insert(copy.end(), nums.begin(), nums.end());
        copy.insert(copy.end(), nums.begin(), nums.end());
        return copy;
    }
};