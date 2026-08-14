class FreqStack {
public:
    FreqStack(): maxFreq(0) {
        
    }
    
    void push(int val) {
        freqCount[val]++;
        freqGroup[freqCount[val]].push_back(val);
        maxFreq = max(maxFreq, freqCount[val]);
    }
    
    int pop() {
        int res = freqGroup[maxFreq].back();
        --freqCount[res];
        freqGroup[maxFreq].pop_back();
        if (freqGroup[maxFreq].empty()) --maxFreq;
        return res;
    }
    unordered_map<int, int> freqCount;
    unordered_map<int, vector<int>> freqGroup;
    int maxFreq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */