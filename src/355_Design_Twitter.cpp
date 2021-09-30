static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Twitter {
public:
    struct greater_than {
        inline bool operator() (const pair<int, int> &i1, 
                                const pair<int, int> &i2) {
            return i1.second > i2.second;
        }    
    };
    
    /** Initialize your data structure here. */
    Twitter() {
        d_time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        /*
        if (10 == d_tweets[userId].size()) {
            d_tweets[userId].pop();    
        }
        d_tweets[userId].push({tweetId, d_time++});*/
        d_tweets[userId].push_back({tweetId, d_time++});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater_than> tweets;
        for (auto tweet:d_tweets[userId]) {
            tweets.push(tweet);
            if (tweets.size() > 10) {
                tweets.pop();
            }
        }
        for (unordered_set<int>::iterator it = d_followee[userId].begin(); it != d_followee[userId].end(); ++it) {
            for (auto tweet:d_tweets[*it]) {
                tweets.push(tweet);
                if (tweets.size() > 10) {
                    tweets.pop();
                }
            }
        }
        vector<int> result;
        while (!tweets.empty()) {
            result.push_back(tweets.top().first);
            tweets.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        d_followee[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (d_followee[followerId].find(followeeId) != d_followee[followerId].end()) {
            d_followee[followerId].erase(d_followee[followerId].find(followeeId));
        }
    }
    
private:
    unsigned int d_time;
    unordered_map<int, unordered_set<int>> d_followee;
    //unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater_than>> d_tweets;
    unordered_map<int, vector<pair<int, int>>> d_tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
