class NumArray {
public:
    NumArray(vector<int>& nums): prefixSum(std::ssize(nums) + 1, 0), n(std::ssize(nums)) {
        if (n == 0) return;
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if (left > right || left < 0 || right < 0 || right >= n) return -1;
        return prefixSum[right + 1] - prefixSum[left];
    }
private:
    vector<int> prefixSum;
    int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */