class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        int n = beginWord.size();
        while(!q.empty()) {
            int qSize = q.size();
            for(int i = 0; i < qSize; i++) {
                auto [word, steps] = q.front();
                q.pop();

                if (word == endWord) return steps;

                for(int j = 0; j < n; j++) {
                    string nextWord = word;
                    for(char c = 'a'; c <= 'z'; c++) {
                        nextWord[j] = c;
                        if (wordSet.count(nextWord)) {
                            q.push({nextWord, steps + 1});
                            wordSet.erase(nextWord);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
