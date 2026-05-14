class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> seen;
        for(const int& num: nums) {
            seen.insert(num);
        }

        int maxLen = 1;
        for(const int& num: seen) {
            if (!seen.contains(num - 1)) {
                int len = 1;
                int next = num + 1;
                while (seen.contains(next)) {
                    len++;
                    next++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
