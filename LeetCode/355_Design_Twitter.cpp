class Twitter {
private:
    unordered_map<int, unordered_set<int>> following;  //user id : {following}
    unordered_map<int, vector<pair<int,int>>> tweets; // user id :  {tweet id , timestamp}
    int time;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        following[userId].insert(userId);

        tweets[userId].push_back({tweetId,time});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        if(following.count(userId)){
            for(auto followee : following[userId]){
                for(int i=tweets[followee].size()-1; i>=0;i--){
                    pq.push({tweets[followee][i].second,tweets[followee][i].first});
                    if (tweets[followee].size() - i > 100) { // Arbitrary heuristic, adjust as needed
                        break; 
                    }
                }
            }
        }

        vector<int> news;
        while(!pq.empty() && news.size()<10){
            news.push_back(pq.top().second);
            pq.pop();
        }
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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