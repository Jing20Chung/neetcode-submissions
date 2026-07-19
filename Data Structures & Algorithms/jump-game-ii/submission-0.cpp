class Solution {
public:
    int jump(vector<int>& nums) {
        int L = 0, R = 0, step = 0;
        while (R < nums.size() - 1) {
            int nextR = 0;
            for(int j = L; j <= R; ++j) {
                nextR = max(nextR, j + nums[j]);
            }
            L = R + 1;
            R = nextR;
            step++;
        }
        return step;
    }
};
