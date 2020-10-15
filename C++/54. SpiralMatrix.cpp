// https://leetcode.com/problems/spiral-matrix/
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

/* Sample input : 
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Sample output :
[1,2,3,6,9,8,7,4,5]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        //number of rows
        int m = matrix.size();
        
        vector<int>v;
        
        if(m==0)return v;

        //number of cols
        int n = matrix[0].size();
       
        int i = 0;
        int j = 0;

        //loop to print in spiral fashion
        while(i<m && j<n){
            for(int l = j; l < n; l++)
            {
                v.push_back(matrix[i][l]);
            }
            i++;
            
            for(int r = i; r < m; r++)
            {
                v.push_back(matrix[r][n-1]);
            }
            n--;
            
            if(j < n && i < m)
            {
                for(int l = n-1 ;l >= j; l--)
                {
                    v.push_back(matrix[m-1][l]);
                }
                m--;
                
            
                for(int r = m-1; r >=i; r--)
                {
                    v.push_back(matrix[r][j]);
                }
                j++;
            }
            
        }
        return v;
    }
};