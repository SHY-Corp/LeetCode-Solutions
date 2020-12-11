// problem - 766. Toeplitz Matrix

/*
    Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

    A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(m == 1 || n == 1) return true;
        
        // traversing diagonally
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
               if(matrix[i][j] != matrix[i-1][j-1]) return false;
            }
        }
        
        return true;
    }
};

// Time Complexity = O(m*n) [where m is row length and n is column length]
// Space Complexity = O(1)