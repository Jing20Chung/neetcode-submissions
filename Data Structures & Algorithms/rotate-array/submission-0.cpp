class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int shift = k % n;

        int count = 0;
        for(int start = 0; count < n; ++start) {
            int cur = start;
            int prev = nums[cur];
            do {
                int nextIdx = (cur + shift) % n;
                int temp = nums[nextIdx];
                nums[nextIdx] = prev;
                prev = temp;
                cur = nextIdx;
                ++count;
            } while (cur != start);
        }
    }
};