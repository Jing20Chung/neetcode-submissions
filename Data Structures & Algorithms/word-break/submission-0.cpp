class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int maxWordLen = INT_MIN;
        for(auto item: dict) {
            maxWordLen = max(maxWordLen, (int) item.size());
        }

        vector<int> dp(s.size(), -1);
        return dfs(0, s, dict, dp, maxWordLen);
    }

    bool dfs(int i, string& s, unordered_set<string>& dict, vector<int>& dp, const int maxWordLen) {
        if (i == s.size()) return true;
        if (dp[i] != -1) return dp[i];

        for(int len = 1; len <= min(maxWordLen, (int)s.size() - i); ++len) {
            if (dict.count(s.substr(i, len)) && dfs(i + len, s, dict, dp, maxWordLen)) {
                dp[i] = 1;
                return true;
            }
        }
        dp[i] = 0;
        return false;
    }
};
