class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            while(!dq.empty() && nums[dq.back()] < num) {
                dq.pop_back();
            }
            dq.push_back(i);

            if(dq.front() <= i - k) {
                dq.pop_front();
            }

            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
