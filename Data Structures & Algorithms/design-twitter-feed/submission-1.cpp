class Twitter {
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweet[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto compare = [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(compare);

        followMap[userId].insert(userId);
        
        for(int followeeId: followMap[userId]) {
            if(userTweet.count(followeeId)) {
                vector<vector<int>>& tweet = userTweet[followeeId];
                int index = tweet.size() - 1;
                maxHeap.push({tweet[index][0], tweet[index][1], followeeId, index});
            }
        }

        vector<int> res;
        while(!maxHeap.empty() && res.size() < 10) {
            vector<int> curr = maxHeap.top();
            maxHeap.pop();

            int tweetId = curr[1];
            int followeeId = curr[2];
            int index = curr[3];

            res.push_back(tweetId);

            if (index > 0) {
                const vector<int>& tweet = userTweet[followeeId][index - 1];
                maxHeap.push({tweet[0], tweet[1], followeeId, index - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }


private:
    int time;
    unordered_map<int, vector<vector<int>>> userTweet;
    unordered_map<int, set<int>> followMap;

};
