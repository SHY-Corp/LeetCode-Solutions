// If we look closely , this problem is very similar to fibonacci problem solution , but this problem require deep insight of recursive tree to figure out  this approach.


class Solution {
public:
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        if(s[0] != '0')
            dp[1]=1;
        
        for(int i=2;i<=n;i++){
            if(s[i-1] != '0')
                dp[i]+=dp[i-1];
            if(s[i-2] =='1' || (s[i-2] =='2' && s[i-1]<='6'))
                dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
