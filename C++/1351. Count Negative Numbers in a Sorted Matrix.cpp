// Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 
// Return the number of negative numbers in grid.
//Runtime beats 94.52% of cpp submission


// Key is to find the first positive number in each row
// Using upper_bound() / binary search we can do this easily

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