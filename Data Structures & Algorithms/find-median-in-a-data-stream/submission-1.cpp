class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap; // put larger portion
    priority_queue<int> maxHeap; // put smaller portion
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // put into the maxHeap
        maxHeap.push(num);

        //choose the greatest number from the left side and push into the right heap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // check if the minHeap size is greater than the maxHeap
        // keep the maxHeap always >= the minHeap
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // we keep maxHeap size always >= minHeap
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        else {
            return (maxHeap.top() + minHeap.top()) / 2.0f;
        }

    }
};
