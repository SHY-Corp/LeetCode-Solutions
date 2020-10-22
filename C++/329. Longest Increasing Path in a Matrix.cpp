class Solution {
public:
    int dp[1005][1005],n,m;
    int solve(vector<vector<int>>& matrix,int ii,int jj){
        if(dp[ii][jj]!=0){
            return dp[ii][jj];
        }
        dp[ii][jj]=1;
        if(ii-1>=0){
            if(matrix[ii-1][jj]<matrix[ii][jj]){
                dp[ii][jj]=max(dp[ii][jj],solve(matrix,ii-1,jj)+1);
            }
        }
        if(jj-1>=0){
            if(matrix[ii][jj-1]<matrix[ii][jj]){
                dp[ii][jj]=max(dp[ii][jj],solve(matrix,ii,jj-1)+1);
            }
        }
        if(ii+1<n){
            if(matrix[ii+1][jj]<matrix[ii][jj]){
                dp[ii][jj]=max(dp[ii][jj],solve(matrix,ii+1,jj)+1);
            }
        }
        if(jj+1<m){
            if(matrix[ii][jj+1]<matrix[ii][jj]){
                dp[ii][jj]=max(dp[ii][jj],solve(matrix,ii,jj+1)+1);
            }
        }
        return dp[ii][jj];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        if(n==0){
            return 0;
        }
        m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==0){
                    solve(matrix,i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
