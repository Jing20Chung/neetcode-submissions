class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxTaskFreq = 0;
        for(const char& task: tasks) {
            freq[task - 'A']++;
            maxTaskFreq = max(maxTaskFreq, freq[task-'A']);
        }

        int slots = (maxTaskFreq - 1) * (n + 1);

        int maxTaskCount = 0;
        for(int i = 0; i < 26; i++) {
            if (freq[i] == maxTaskFreq) maxTaskCount++;
        }

        int totalCycle = slots + maxTaskCount;

        return max(totalCycle, (int)tasks.size());
    }
};
