class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        if (words.size() == 0) return "";

        unordered_map<char, int> indegreeMap;
        for(const string& word: words) {
            for(const char c: word) {
                if (!indegreeMap.contains(c)) indegreeMap[c] = 0;
            }
        }

        vector<unordered_set<char>> path(26);
        for(int i = 0; i < words.size() - 1; ++i) {
            string word1 = words[i];
            string word2 = words[i + 1];

            if (word1.size() > word2.size() && word1.compare(0, word2.size(), word2) == 0) return "";
            int minSize = min(word1.size(), word2.size());

            for(int j = 0; j < minSize; ++j) {
                if (word1[j] != word2[j]) {
                    if (path[word1[j] - 'a'].insert(word2[j]).second) { // insert successfully
                        indegreeMap[word2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for(auto[c, indegree]: indegreeMap) {
            if (indegree == 0) {
                q.push(c);
            }
        }

        string ans;
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            ans += c;
            int index = c - 'a';
            for(auto nei: path[index]) {
                indegreeMap[nei]--;
                if (indegreeMap[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if (ans.size() != indegreeMap.size()) return "";
        return ans;
    }
};
