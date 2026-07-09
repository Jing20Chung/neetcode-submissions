class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxCnt = INT_MIN;
        for(int cnt: piles) {
            maxCnt = max(maxCnt, cnt);
        }

        int lo = 1, hi = maxCnt;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canConsume(piles, mid, h)) { // try smaller k
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    bool canConsume(const vector<int>& piles, int k, int h) {
        int hour = 0;
        for (int pile: piles) {
            hour += (pile + k - 1) / k;
            if (hour > h) return false;
        }
        return true;
    }
};
