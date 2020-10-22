/*
Problem Satement:-
A robot is located at the top-left corner of a m x n grid 
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

The solution uses Dynamic approach to find the total number of unique paths for the robot to reach end point (n-1,m-1) from start point(0,0)
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size();
        int m = Grid[0].size();

        if (Grid[0][0] == 1) {
            return 0;
        }

        Grid[0][0] = 1;

        for (int i = 1; i < n; i++) 
        {
            if (Grid[i][0] == 0 && Grid[i - 1][0] == 1)
            {
                Grid[i][0] = 1 ;
            }
            else
            {
                Grid[i][0] =0;
            }
        }

        for (int i = 1; i < m; i++) 
        {
            if (Grid[0][i] == 0 && Grid[0][i - 1] == 1) 
            {
                Grid[0][i] = 1;
            }
            else
            {
                Grid[0][i] =0;
            }
        }

        for (int i = 1; i < n; i++) 
        {
            for (int j = 1; j < m; j++) 
            {
                if (Grid[i][j] == 0) 
                {
                    Grid[i][j] = Grid[i - 1][j] + Grid[i][j - 1];
                } 
                else 
                {
                    Grid[i][j] = 0;
                }
            }
        }


        return Grid[n - 1][m - 1];
    }

};
