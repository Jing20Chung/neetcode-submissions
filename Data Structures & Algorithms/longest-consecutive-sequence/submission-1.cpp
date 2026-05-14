class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        int maxLen = 0;
        for(int &num : nums) {
            seen.insert(num);
        }

        for(int & num: nums) {
            if (!seen.count(num - 1)) {
                int cur = num;
                int len = 1;
                while (seen.count(cur + 1)) {
                    seen.erase(cur);
                    cur++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }


        return maxLen;
    }
};
