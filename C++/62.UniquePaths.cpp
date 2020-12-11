class Solution {
public:
    int uniquePaths(int m, int n) {
        /* I am declaring a variable here which stores the no. of unique paths
           from start to finish, depending upon which index we are at.
           If the Finish point is at [2,2] and the Start point is at [0,0],
           we can go to index from Finish taking 2 unique paths. We use this
           information to further see how we can go from [3,3] to [0,0] or for that
           matter, from [m,n] to Start!
        */
        
        int path[m][n];
        int i, j;
        
        for(i=0; i<m; i++)         //i~m, j~n; Also, we hold this condition till (m-1) and (n-1)
        {
            for(j=0; j<n; j++)
            {
                if(i==0||j==0)
                    path[i][j]=1;  //Since we are only going in one direction, either down or right!
                else
                    path[i][j]=path[i-1][j]+path[i][j-1];
            }
        }
        return path[m-1][n-1];     //since we are counting from zero index!
    }
};