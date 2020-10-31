class Solution {
public:
    int numWays(vector<string>& words, string target) {
        long long int dp[1005][1005];
        int cnt[1005][26];
        memset(cnt, 0, sizeof(cnt));
        
        for(auto word: words)
            for(int i=0; i<word.size(); i++)
                cnt[i][word[i] - 'a']++;
        
        int ans = 1;
        int mod = 1e9 + 7;
        dp[0][0] = 1;
        
        int tl = target.size(), wl = words[0].size();
        for(int i=0; i<=tl; i++)
            for(int j=0; j<=wl; j++){
                if (i==j && i == 0) continue;
                if(i==0) dp[i][j] = dp[i][j-1];
                
                else{
                    if(j){
                        dp[i][j] = dp[i][j-1] + dp[i-1][j-1] * cnt[j-1][target[i-1] - 'a'];
                        dp[i][j] %= mod;
                    }
                }
            }
        
        return dp[tl][wl];
    }
};
