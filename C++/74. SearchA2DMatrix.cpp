/*Search a 2D Matrix */

/*PROBLEM STATEMENT*/
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

*/

/*EXAMPLES*/
/*
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //base case
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        int left = 0;
        
        int right = matrix[0].size()-1;

        for(int i=matrix.size()-1 ;  i >= 0; i--){
            //serach in every row for the target
            if (matrix[i][left] <= target && matrix[i][right] >= target){

                //if target is found in a row then apply binary search
                while( left <= right ){
                    int mid = (left+right)/2;
                    if (matrix[i][mid] == target){
                        return true;
                    }
                    if (matrix[i][mid] > target){
                        right = mid-1;
                    }else{
                        left = mid+1;
                    }
                }
                return false;
            }
        }
        return false;
        
    }
};