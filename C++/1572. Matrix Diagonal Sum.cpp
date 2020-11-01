/*Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal(digonal from top-left corner to bottom-right corner) and
all the elements on the secondary diagonal(top-right corner to bottom-left corner) that are not part of the primary diagonal.*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int left=0,right=n-1,sum=0;
        for(int i=0;i<n;i++){
          sum+=mat[i][left++]+mat[i][right--];
        }
        if(n%2!=0){
            sum-=mat[n/2][n/2];
        }
        return sum;
    }
};
