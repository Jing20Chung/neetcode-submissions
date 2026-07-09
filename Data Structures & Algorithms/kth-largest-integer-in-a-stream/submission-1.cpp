class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int _k;
public:
    KthLargest(int k, vector<int>& nums): minHeap(nums.begin(), nums.end()), _k(k) {
        while(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > _k) minHeap.pop();
        return minHeap.top();
    }
};
