class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if (k < 1 || arr.size() < k) return 0;
        long long curSum = 0;
        long long targetSum = threshold * k;
        for(int R = 0; R < k; R++) {
            curSum += arr[R];
        }

        int count = curSum >= targetSum;

        for(int R = k; R < arr.size(); ++R) {
            curSum = curSum - arr[R - k] + arr[R];
            count += (curSum >= targetSum);
        }

        return count;
    }
};