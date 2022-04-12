class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        //creating a result vector of row * col dimensions
        vector<vector<int>> shifted(row, vector<int>(col, 0));

        //iterating from 0 to (row*col)-1 to store the elements into result matrix
        for(int i=0; i<row*col; i++)
        {
            //the variable from which shifting takes place after each iteration
            int temp = (i+k)%(row*col);

            //i/col = row number and i%col = column number of original vector and storing the value at these
            //indices to the resultant vector
            shifted[temp/col][temp%col] = grid[i/col][i%col];
        }
        return shifted;
    }
};

/*
   TC: O(row*col)
   SC: O(row*col)
*/
