class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<>> minHeap;

        for(int num: hand) {
            if (!mp.contains(num)) {
                minHeap.push(num);
            }
            mp[num]++;
        }

        while(!minHeap.empty()) {
            int curTop = minHeap.top();
            if (mp[curTop] == 0) minHeap.pop();
            else {
                for(int i = curTop; i < curTop + groupSize; ++i) {
                    if (!mp.contains(i) || mp[i] <= 0) return false;
                    mp[i]--;
                }
            }
        }

        return true;
    }
};
