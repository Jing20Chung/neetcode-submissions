class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int& num: nums) {
            if (freq.find(num) != freq.end()) {
                freq[num]++;
            }
            else {
                freq[num] = 1;
            }
        }

        vector<vector<int>> count = vector<vector<int>>(n + 1, vector<int>());
        for (auto &pair: freq) {
            count[pair.second].push_back(pair.first);
        }

        vector<int> ans;
        int i = n;
        while(k > 0 && i >= 0) {
            if (count[i].size() != 0){
                for(int &item: count[i]) {
                    ans.push_back(item);
                    k--;
                }
            }
            i--;
        }
        return ans;
    }
};
