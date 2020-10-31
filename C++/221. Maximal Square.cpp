/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if(r==0)
            return 0;
        int c = matrix[0].size();
        int dp[r+1][c+1];
        for(int i=0;i<=r;i++){
            for(int j=0;j<=c;j++){
                    dp[i][j]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c ;j++)
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    if(ans<dp[i][j])
                        ans=dp[i][j];
                }
        }
        return ans*ans;
        
    }
};
