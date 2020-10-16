class Solution {
public:
    
    static bool srt(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.first!=b.first)
            return a.first<b.first;
        
        return a.second <b.second;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
       int n=position.size();
        
        if(n<=1)
            return n;
            
        
        vector<pair<int,int>> v(n);
        
        for(int i=0;i<n;i++)
        {
            v[i] = {position[i], speed[i]};
        }
        
        sort(v.begin(),v.end(),srt);
        
        //idx is the index of the car closest to the destination at first
        int idx = n-1, c=1;
        
        //moving in reverse
        for(int i=n-1; i>=0 ; i--)
        {
            //note dist of i then speed of idx and vice versa- avoiding div, so inverse pro
            // just checking if time i>time idx, then cant merge and increase count of grps
            //also as idx will finish, i becomes next fastest - so update idx = i.
            long long time1 = (long long) (target - v[i].first)*v[idx].second;
            long long time2 = (long long)(target - v[idx].first)*v[i].second;
            
            if(time1 > time2)
            {
                c++;
                idx = i;
            }
        }
        
        return c;
    }
};