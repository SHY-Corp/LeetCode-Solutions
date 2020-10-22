/**
* Problem link: https://leetcode.com/problems/distinct-subsequences/
* Problem explanation:
* Given a string S and a string T, count the number of distinct subsequences of S which equals T.
* A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the
* characters without disturbing the relative positions of the remaining characters.
* (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not) It's guaranteed the answer fits on a 32-bit signed integer.
*/
class Solution {
public:
    #define ll long long
    int numDistinct(string s, string t) {

        int n = s.size(), m = t.size();

        // dynamic programming matrix
        // dp(i,j) is equal to the number of subsequences that make the first j letters of t
        // with the first i letters of s
        // dp transitions dp(i,j) = dp(i-1,j)
        // dp(i,j) += dp(i-1,j-1) if s[i] == s[j]
        ll dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i <= n;++i)
            dp[i][0] = 1;

        for(int i = 1; i <= n;++i){
            for(int j = 1;j <= m;++j){
                //the number of ways that make subsequences of the first j letters of t
                //with the first i letters of s is always equal the number number of subsequences
                //with the first i - 1 letters of s
                dp[i][j] = dp[i-1][j];

                if(s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        }
        //the answer is always an int, but along the way it may overflow
        return dp[n][m];
    }
};

