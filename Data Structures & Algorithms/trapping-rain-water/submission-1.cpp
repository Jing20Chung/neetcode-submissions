class Solution {
public:
    int trap(vector<int>& height) {
        if (std::ssize(height) < 2) return 0;

        int L = 0, R = std::ssize(height) - 1;
        int maxHL = height[L], maxHR = height[R];
        int water = 0;
        while (L < R) {
            if (maxHL < maxHR) {
                L++;
                maxHL = max(maxHL, height[L]);
                water += maxHL - height[L];
            }
            else {
                R--;
                maxHR = max(maxHR, height[R]);
                water += maxHR - height[R];
            }
        }
        return water;
    }
};
