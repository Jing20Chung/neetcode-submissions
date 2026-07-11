class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0, R = std::ssize(heights) - 1;
        int maxA = 0;
        while (L < R) {
            if (heights[L] < heights[R]) {
                maxA = max(maxA, (R - L) * heights[L]);
                L++;
            }
            else {
                maxA = max(maxA, (R - L) * heights[R]);
                R--;
            }
        }
        return maxA;
    }
};
