class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int result = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] < leftMax) {
                    result += leftMax - height[l];
                }
                else {
                    leftMax = height[l];
                }
                l++;
            }
            else {
                if (height[r] < rightMax) {
                    result += rightMax - height[r];
                }
                else {
                    rightMax = height[r];
                }
                r--;
            }
        }
        return result;
    }
};
