class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int m = *max_element(people.begin(), people.end());
        vector<int> count(m + 1, 0);
        for(int w: people) {
            ++count[w];
        }
        
        int idx = 0;
        int i = 0;
        while(idx < n) {
            while(count[i] == 0) ++i;
            people[idx++] = i;
            count[i]--;
        }
        
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