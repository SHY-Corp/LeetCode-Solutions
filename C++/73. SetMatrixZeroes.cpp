// Problem - 73. Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Declare variable
        const int H = matrix.size();
        const int W = matrix[0].size();
        bool first_row_zero = false;
        // Check the first row in the matrix.
        // If a certain position has a value of 0, the first_row_zero flag will turn on
        for (int col = 0; col < W; ++col){
            if(matrix[0][col] == 0){
                first_row_zero = true;
            }
        }
        // Go through the matrix, if any position has a value of 0 (matrix[row][col] = 0)
        // Change the matrix value at the row 0, column position that found with value 0 (matrix[0][col] = 0)
        for (int row = 0; row < H; ++row){
            for (int col = 0; col < W; ++col){
                if (matrix[row][col] == 0){
                    matrix[0][col] = 0;   
                }
            }
        }
        // Next, browse the matrix from row 1 column col. If a position has a value of 0
        // Change whole row is equal to 0 
        for (int row = 1; row < H; ++row){
            bool contains_zero = false;
            for (int col = 0; col < W; ++col){
                if (matrix[row][col] == 0){
                    contains_zero = true;
                    break;
                }
            }
            for (int col = 0; col < W; ++col){
                if(contains_zero || matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
            }
        }
        // A special case, if the matrix has a value of 0 in the first row that checked above
        // Change whole row 0 is equal to 0 
        if (first_row_zero){
            for (int col = 0; col < W; ++col){
                matrix[0][col] = 0;
            }
        }
    }
};