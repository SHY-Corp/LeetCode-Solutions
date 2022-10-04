class Solution {
public:
    
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int dp[n + 1][m + 1];
        dp[0][0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 or j == 0) dp[i][j] = 0;
                else if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string res("");
        int i = n, j = m;
        while (i > 0 and j > 0) {
            if (str1[i - 1] == str2[j - 1]) res = str1[i - 1] + res, i--, j--;
            else if (dp[i - 1][j] > dp[i][j - 1]) res = str1[i - 1] + res, i--;
            else res = str2[j - 1] + res, j--;
        }
        while (j > 0) res = str2[--j] + res;
        while (i > 0) res = str1[--i] + res;
        return res;
        
    }
};
