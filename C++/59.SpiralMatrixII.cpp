class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int gridValue = 1;
        int rowStart = 0, colStart = 0, rowEnd = n-1, colEnd = n-1;
        vector<vector<int>> v(n, vector<int>(n));

        while(rowStart<=rowEnd && colStart<=colEnd)
        {
            //for moving from LEFT->RIGHT; row=constant, column=changes
            for(int i=colStart; i<=colEnd; i++)
                v[rowStart][i] = gridValue++;

            //incrementing this value because we will iterate from the next row in the subsequent step
            rowStart++;

            //for moving from  TOP->BOTTOM; row=changes, column=constant
            for(int i=rowStart; i<=colEnd ; i++)
                v[i][colEnd] = gridValue++;

            //decrementing this because we will iterate from the column before the previous column
            colEnd--;

            //for moving from RIGHT->LEFT; row=constant, column=changes
            for(int i=colEnd; i>=colStart; i--)
                v[rowEnd][i] = gridValue++;

            //we will now iterate from the row before the previously processed row
            rowEnd--;

            //for moving from BOTTOM->TOP; row=changes, column=constant
            for(int i=rowEnd; i>=rowStart; i--)
                v[i][colStart] = gridValue++;

            //incrementing this value, we will iterate from the next column one the previous column is done
            colStart++;
        }
    return v;
    }
};

/*
   TC: O(n*n), since we are iterating over the matrix in spiral
   SC: O(1), for storing the gridValue
*/
