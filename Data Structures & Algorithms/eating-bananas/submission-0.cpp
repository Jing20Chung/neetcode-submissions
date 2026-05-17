class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;
        for(const int& pile: piles) {
            r = max(r, pile);
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(hourToEat(mid, piles) > h) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
    }

    long long hourToEat(int spd, vector<int>& piles){
        long long totalH = 0;
        for(const int& pile: piles) {
            totalH += (pile + spd - 1) / spd;
        }
        return totalH;
    }
};
