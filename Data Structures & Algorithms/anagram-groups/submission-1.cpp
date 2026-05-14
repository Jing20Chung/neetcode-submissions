class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> resultMapping;

        for(string str: strs) {
            int wordCount[26] = {0};
            for (char c: str) {
                wordCount[c - 'a']++;
            }

            string key;
            for (int i = 0; i < 26; i++) {
                if (wordCount[i] != 0) {
                    key += static_cast<char>('a' + i);
                    key += "#";
                    key += to_string(wordCount[i]);
                }
            }

            resultMapping[key].push_back(str);
        }

        for(auto& kv: resultMapping) {
            result.push_back(std::move(kv.second));
        }
        return result;
    }
};
