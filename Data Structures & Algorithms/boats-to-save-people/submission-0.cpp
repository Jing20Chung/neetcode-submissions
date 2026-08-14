class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0, r = n - 1, ans = 0;
        while (l <= r) {
            int remain = limit - people[r];
            ++ans;
            --r;
            if (l <= r && remain >= people[l]) {
                ++l;
            }
        }
        return ans;
    }
};