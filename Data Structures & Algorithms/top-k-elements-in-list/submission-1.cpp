class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        int i = n;
        unordered_map<int, int> freq;
        vector<vector<int>> count = vector<vector<int>>(n + 1, vector<int>());
        vector<int> ans;
        for(int& num: nums) {
            freq[num]++;
        }

        for (auto &pair: freq) {
            count[pair.second].push_back(pair.first);
        }

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
