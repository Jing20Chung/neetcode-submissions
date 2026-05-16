class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for(int i = 0; i < s1.size(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        if (s1Count == s2Count) return true;
        for (int r = s1.size(); r < s2.size(); r++) {
            s2Count[s2[r] - 'a']++;
            s2Count[s2[r - s1.size()] - 'a']--;
            if (s1Count == s2Count) return true;
        }

        return false;
    }
};
