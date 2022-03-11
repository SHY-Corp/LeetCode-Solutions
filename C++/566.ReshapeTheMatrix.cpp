class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       /* vector<int> temp;

        int row = mat.size();
        int col = mat[0].size();

        if((row*col<r*c) || (row*col>r*c))
            return mat;

        //can be done using flatten function too!
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                temp.push_back(mat[i][j]);
            }
        }

       vector<vector<int>> result(r, vector<int>(c,0));
       int index=0; //index for iterating over temp & pushing their values into the result vector

       for(int i=0; i<r; i++)
       {
           for(int j=0; j<c; j++)
           {
               result[i][j] = temp[index];
               index++;
           }
       }

       return result; */

        int row = mat.size();
        int col = mat[0].size();

        int rcProduct = row * col;

        if(r*c != rcProduct)
            return mat;

        //creating a result vector of r * c dimensions
        vector<vector<int>> result(r, vector<int>(c, 0));

        //iterating from 0 to rcProduct-1 to store the elements into reshaped matrix
        for(int i=0; i<rcProduct; i++)
        {
            //i/c = row number and i%c = column number of result vector
            //storing the elements of mat into the reshaped matrix of appropriate index
            result[i/c][i%c] = mat[i/col][i%col];
        }
        return result;
    }
};

/*
   1st approach: TC = O(row*col), SC = O(r*c)+O(row*col) = O(2*r*c)
   2nd approach: Reduced the extra(additional temp vector) space
                 TC = O(r*c), SC = O(r*c)

   Example:
   mat = [[1,2],                       result = [[1,2,3,4]], r = 1, c = 4
          [3,4]],   row =2, col = 2
   rcProduct=4(i=0,1,2,3)
                                                                 i/c  i%c      i/col i%col
   i=0   index(1) = [0,0]  -> result[0][0] = mat[0][0] => result[0/4][0%4] = mat[0/2][0%2]
   i=1   index(2) = [0,1]  -> result[0][1] = mat[0][1] => result[1/4][1%4] = mat[1/2][1%2]
   i=2   index(3) = [1,0]  -> result[0][2] = mat[1][0] => result[2/4][2%4] = mat[2/2][2%2]
   i=3   index(4) = [1,1]  -> result[0][3] = mat[1][1] => result[3/4][3%4] = mat[3/2][3%2]

*/
