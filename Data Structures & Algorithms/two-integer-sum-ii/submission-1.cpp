class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = std::ssize(numbers) - 1;
        while (l < r) {
            long long sum = numbers[l] + numbers[r];
            if (sum < target) {
                l++;
            }
            else if (sum > target) {
                r--;
            }
            else {
                return {l + 1, r + 1};
            }
        }
        return {};
    }
};
