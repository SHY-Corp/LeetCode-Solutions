// Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 
// Return the number of negative numbers in grid.



// Key is to find the first positive number in each row
// Using upper_bound() / binary search we can do this easily


// Method - 1 
// Runtime beats 94.52% of cpp submission
// This solution suits best if your are known to STL functions 



/*
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        // Initialize result 
        unsigned int negative_count = 0;
        
        for (int r = 0; r < grid.size(); r++) {
            
            // if first integer is negative then full row will be negative
            if (grid[r][0] < 0) {
                negative_count += (grid.size() - r) * grid[0].size();
                break;
            }
            
            // reverse array
            reverse(grid[r].begin(), grid[r].end());
            
            // find postition of first postive number ie. greater than -1
            int pos = upper_bound(grid[r].begin(), grid[r].end(), -1) - grid[r].begin();
            
            // adds negative number count to result
            negative_count += pos;
        }
        
        return negative_count;
    }
};

*/



// Method 2
//This solution beats 99.41% in run time  

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
    
        
        int count = 0;
        
        int i = 0; // used for traversing

        // to get the number of rows
        int row = grid.size()-1;
        
        //to get the size of the column 
        int col = grid[0].size()-1;
    
        
        int j ;
        
        while (i <= row )
        {
            // if the elements of column are ascending 
            // then j points to  end element of column and then traversing from back to avoid extra steps
            // otherwise j points to the starting of the column and simple traverse

             bool ascend = grid[0][0] < grid[0][col] ? j = col  : j = 0 ;
            while ( ascend && j>=0)
            {
                if (grid[i][j] < 0)
                {
                    count += j+1;
                break;

                }
                j-- ;
            }
            
            // run when if the column is if descending order
            while (j <= col)
            {
                if (grid[i][j] < 0)
                {
                    count += (col +1 - (j));
                break;

                }
                j++; 
                
            }
            i++ ;
        }
        
        return count ;
        
        
    }
};
