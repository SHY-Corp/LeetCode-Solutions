/* Given a string S, count the number of distinct, non-empty subsequences of S .

Since the result may be large, return the answer modulo 10^9 + 7. */

// Import neccessary header files.

class Solution {
public:
int distinctSubseqII(string S) {

    S = "$" + S;
    int n = S.length();
    vector<long> dp(n, 0);
    vector<int> lastPos(26, -1);

    int mod = 1e9 + 7;
    
    for(int i = 0; i < n; i++) {
        if(i == 0) { // empty string
            dp[i] = 1;
            continue;
        }

        dp[i] = 2 * dp[i - 1] % mod;
        if(lastPos[S[i] - 'a'] != -1) {
            dp[i] = dp[i] % mod - dp[lastPos[S[i] - 'a'] - 1] % mod + mod;
        }

        lastPos[S[i] - 'a'] = i;
    }

    // for removing $
    return dp[n - 1] % mod - 1;
}
};