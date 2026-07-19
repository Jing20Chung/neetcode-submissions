class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(char c: s) {
            mp[c]++;
        }
        vector<int> ans;
        unordered_set<char> track;
        int l = 0;
        for(int r = 0; r < s.size(); r++) {
            char cur = s[r];
            if (track.count(cur) == 0) {
                track.insert(cur);
            }
            mp[cur]--;
            if (mp[cur] == 0) {
                track.erase(cur);
            }
            if (track.empty()) {
                ans.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return ans;
    }
};
