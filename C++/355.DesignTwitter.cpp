class Twitter {
public:
    /** Initialize your data structure here. */
    /*1) An hashtable to store tweets of the corresponding user .
    The tweets are stored in a queue so as to keep track of the recent tweets.
    The pair denotes the time ( take most recent 10 tweets ) and tweets of a user.
    2) Hashtable to keep Track of Followers (who follows whom) to fetch their tweets on the 
    corresponding user's feed.
    3) Static variable time to denote when the tweets are posted 
    */


    
    map<int,queue<pair<int,int>>> tweets;
    map<int,set<int>> followers;
    int time=0;
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    /* Tweets are posted by a user are stored in a queue
      If suppose the tweets of a particular user exceed 10 we pop the old tweets
      Since only 10 is needed.
    */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push({time++,tweetId});
        
        if(tweets[userId].size()>10)
        {
            tweets[userId].pop();
        }
       
       
        
        
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    
    vector<int> getNewsFeed(int userId) {
        
        vector<int> ans;
        //Priority queue to take top 10 tweets based on time (max heap)
        priority_queue<pair<int,int>> q;
        
        //Tweets of the person
       queue<pair<int,int>> t=tweets[userId];
        
        while(!t.empty())
        {
            q.push(t.front());
            t.pop();
        }
        
        // Tweets of all the followers of the users
        for(auto foll: followers[userId])
        {
            t=tweets[foll];
            while(!t.empty())
            {
                q.push(t.front());
                t.pop();
            }
              
        }
        
        int k=0;
        
        // Most recent 10 tweets
        while(!q.empty() && k<10)
        {
            ans.push_back(q.top().second);
            q.pop();
             k++;
        }
        return ans;
        
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!= followeeId)followers[followerId].insert(followeeId);
      
    
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        
         followers[followerId].erase(followeeId); 
        
      
    }
};
