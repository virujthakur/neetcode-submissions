class Twitter {
public:
    unordered_map<int,deque<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> followers;
    int time = 0;

    Twitter() {
        
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
        if(tweets[userId].size() > 10){
            tweets[userId].pop_front();
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        followers[userId].insert(userId);
        vector<int> recentTweets;
        priority_queue<vector<int>> maxHeap;
        if(followers[userId].size() >=10){
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
            for(auto f: followers[userId]){
                minHeap.push({tweets[f].back().first, tweets[f].back().second, (int)tweets[f].size()-1, f});
                if(minHeap.size() > 10) minHeap.pop();
            }
            while(minHeap.size() > 0){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else{
            for(auto f: followers[userId]){
                if(tweets[f].size() > 0)
                    maxHeap.push({tweets[f].back().first, tweets[f].back().second, (int)tweets[f].size()-1, f});
            }
        }

        while(!maxHeap.empty() and recentTweets.size() < 10){
            auto cur = maxHeap.top();
            maxHeap.pop();
            int tweetId = cur[1];

            recentTweets.push_back(tweetId);
            int newIdx = cur[2]-1;
            int f = cur[3];
            if(newIdx >=0){
                maxHeap.push({tweets[f][newIdx].first, tweets[f][newIdx].second, newIdx, f});
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
