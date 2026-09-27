class Twitter {
public:
    unordered_map<int, unordered_set<int>>following;//userID, List of the ppl they follow
    // userId -> {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timestamp = 0;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<
            tuple<int, int, int, int>
        > pq; //timestamp, tweetId, userId, index in user's tweets
        //user's own top tweet
        if(!tweets[userId].empty()){
            int i = tweets[userId].size()-1;
            pq.push({tweets[userId][i].first,
                tweets[userId][i].second,
                userId,
                i
            });
        }
        //followee's latest tweets
        for(int followee : following[userId]){
            if (!tweets[followee].empty()) {
                int i = tweets[followee].size()-1;
            pq.push({tweets[followee][i].first,
                tweets[followee][i].second,
                followee,
                i
            });
            }
        }
        vector<int>feed;
        // Get latest 10 tweets
        while (!pq.empty() && feed.size() < 10) {
            auto [time, tweetId, user, index] = pq.top();
            pq.pop();
            feed.push_back(tweetId);
            if (index > 0) {

                index--;

                pq.push({
                    tweets[user][index].first,
                    tweets[user][index].second,
                    user,
                    index
                });
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
