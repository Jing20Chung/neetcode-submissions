class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while(maxHeap.size() >= 2) {
            int newStone = maxHeap.top();
            maxHeap.pop();
            newStone = abs(newStone - maxHeap.top());
            maxHeap.pop();
            if(newStone != 0) maxHeap.push(newStone);
        }

        if (!maxHeap.empty()) return maxHeap.top();
        else return 0;
    }
};
