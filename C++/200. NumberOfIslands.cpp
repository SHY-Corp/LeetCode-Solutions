// Link to the problem : https://leetcode.com/problems/number-of-islands/submissions/
// Problem Name : Number of islands

/* Problem : Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water. */

/* Example : Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1 */

// Solution Method : Depth First Search (DFS)

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '2';
        if(i > 0) {
            if(grid[i-1][j] == '1')
                dfs(grid,i-1,j);
        }
        if(j < grid[i].size() - 1) {
            if(grid[i][j+1] == '1')
                dfs(grid,i,j+1);
        }
        if(i < grid.size() - 1) {
            if(grid[i+1][j] == '1')
                dfs(grid,i+1,j);
        } 
        if(j > 0) {
            if(grid[i][j-1] == '1')
                dfs(grid,i, j-1);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0;i < grid.size(); i++) {
            for(int j = 0;j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid,i,j);
                }
            } 
        }
        return count;
    }
    
};
