class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canShip(weights, mid, days)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool canShip(vector<int>& weights, const int cap, const int days) {
        int remain = cap;
        int cnt = 1;
        for(const int w: weights) {
            if (remain < w) {
                ++cnt;
                if (cnt > days) return false;
                remain = cap;
            }
            remain -= w;
        }
        return true;
    }
};