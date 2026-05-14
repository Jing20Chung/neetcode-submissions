class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int s_map[26] = {0};
        int t_map[26] = {0};

        for(int i = 0; i < s.size(); i++) {
            s_map[s[i] - 'a']++;
            t_map[t[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if (s_map[i] != t_map[i]) return false;
        }

        return true;
    }
};
