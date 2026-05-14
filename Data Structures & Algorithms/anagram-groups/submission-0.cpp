class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        for(string str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            dict[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto const& pair: dict) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
