class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // curSum - preSum[j] = k
        // preSum[j] = curSum - k

        // curSum - preSum = k
        // preSum = curSum - k
        // preSumCount[curSum] <- how many times this kind of curSum
        // appear in the arr

        auto n = std::ssize(nums);
        unordered_map<long long, int> preSumCount;
        long long curSum = 0, ans = 0;
        preSumCount[0] = 1; // default sum is 0
        for(auto i = 0; i < n; i++) {
            curSum += nums[i];
            long long target = curSum - k;
            if (preSumCount.contains(target)) {
                ans += preSumCount[target];
            }
            preSumCount[curSum]++;
        }
        return ans;
    }
};