class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> record;
        vector<int> result(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++) {
            while (!record.empty() && temperatures[record.top()] < temperatures[i]) {
                int prevIdx = record.top();
                record.pop();
                result[prevIdx] = i - prevIdx;
            }
            record.push(i);
        }
        return result;
    }
};
