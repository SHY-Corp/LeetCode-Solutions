/*1277. Count Square Submatrices with All Ones

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

//If we choose a block, its left,right and diagonal will provide information whether it is a square or not
/*As an example, consider below matrix
[1,1,1]
[1,1,1]
[1,1,1]
Looking at the second row and second column we can see that this will form square
We store the number of squares made by it = min(right ,left,diagonal) +1

*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
		int r=matrix.size()
		int c=matrxi[0].size()
        int dp[r][c];
        int res=0;
        for(int i=0;i<r;i++)
        {   for(int j=0;j<c;j++)
            {   if(i==0||j==0)
                    dp[i][j]=matrix[i][j];
                else
                {
                    if(matrix[i][j]==0)
                        dp[i][j]=0;
                    else
                        dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
                res=res+dp[i][j];
            }
        }
        return res;
        
    }
};