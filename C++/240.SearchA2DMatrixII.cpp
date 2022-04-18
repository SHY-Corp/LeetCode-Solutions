class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        //matrix index values from which we start traversing, in this case, top-right corner
        int r = 0;
        int c = col-1;

        //starting from top-right corner in the matrix and traversing till we reach the boundary
        while(r<row & c>=0)
        {
            if(target==matrix[r][c])
                return true;

            //rejecting the entire COLUMN if target is less than the current matrix value
            else if(target < matrix[r][c])
                c--;
            //rejecting the entire ROW if the target is more than the current matrix value
            else
                r++;
        }
        return false;
    }
};

/*
    TC: O(row+col), the path traversed from top-right cornet to target
    SC: O(1)
*/
