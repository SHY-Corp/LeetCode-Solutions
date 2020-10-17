/*
Problem - Number of Islands
Problem Number - 200

Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.


Example 1:-
Input: grid =
[
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]

Output: 1


Example 2:-
Input: grid =
[
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

Output: 3

*/

/*Approach
1. Iterate over the elements of the 2D matrix and whenever '1' is encountered perform a DFS which is done by helper function in this case
2. While performind DFS check the elements in the adjacent(top, bottom, left, right) to the current element recursively and change the element to '0' if it is '1'
3. Increase the counter when one such iteration is completed
4. Return counter
*/

class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0')
        {
            return;
        }

        grid[i][j]='0';
        helper(grid,i+1,j);
        helper(grid,i-1,j);
        helper(grid,i,j+1);
        helper(grid,i,j-1);
    }


    int numIslands(vector<vector<char>>& grid)
    {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    helper(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
