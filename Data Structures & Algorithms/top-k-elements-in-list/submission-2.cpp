class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int num: nums) {
            freq[num]++;
        }

        vector<vector<int>> freqBucket(n + 1);
        for (auto& kv: freq) {
            freqBucket[kv.second].push_back(kv.first);
        }

        vector<int> result;
        for (int i = n; i >= 0; i--) {
            for (int item: freqBucket[i]) {
                result.push_back(item);
                k--;
                if (k == 0) return result;
            }
        }
        return result;
    }
};
