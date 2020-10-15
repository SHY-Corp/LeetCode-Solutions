// Leetcode Problem 48

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //transpose of matrix
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<i; j++) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
            }
        }
        
        //reverse columns
        for(int j=0; j<matrix.size(); j++) {
            int start=0;
            int end = matrix.size()-1;
        
            while(start<end) {
                int temp = matrix[j][start];
                matrix[j][start] = matrix[j][end];
                matrix[j][end] = temp;
            
                start++;
                end--;
            }
        }
    }
};