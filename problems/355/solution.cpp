class Twitter {
private:
    int time = 0;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, deque<pair<int, int>>> tweets;

public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
        
        if (tweets[userId].size() > 10) {
            tweets[userId].pop_front();
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> feed;
        
        for (const pair<int, int>& tweet: tweets[userId]) {
            feed.push(tweet);
            
            if (feed.size() > 10) {
                feed.pop();
            }
        }
        
        for (const int& followerId: followers[userId]) {
            for (const pair<int, int>& tweet: tweets[followerId]) {
                feed.push(tweet);
                
                if (feed.size() > 10) {
                    feed.pop();
                }
            }
        }
        
        vector<int> ans(feed.size());
        
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = feed.top().second;
            feed.pop();
        }
        
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        
        followers[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        
        if (followers[followerId].count(followeeId)) {
            followers[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */