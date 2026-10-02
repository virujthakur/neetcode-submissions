class Twitter {
public:
    vector<pair<int,int>> tweets;
    unordered_map<int, unordered_set<int>> followers;
    Twitter() {
        
    }
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int n= tweets.size();
        vector<int> recentTweets;
        for(int i=n-1; i>=0; i--){
            if(tweets[i].first == userId or followers[userId].count(tweets[i].first)!=0){
                recentTweets.push_back(tweets[i].second);
                if(recentTweets.size() == 10) break;
            }
        }
        return recentTweets;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
