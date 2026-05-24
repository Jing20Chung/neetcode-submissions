class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);

        right.push(left.top());
        left.pop();

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }
        else {
            return (right.top() + left.top())/2.0;
        }
    }
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
};
