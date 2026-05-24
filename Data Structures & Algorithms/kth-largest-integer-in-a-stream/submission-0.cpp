class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(const int& num: nums) {
            minHeap.push(num);
        }

        while(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
