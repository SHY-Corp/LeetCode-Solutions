# Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise
# code is to find the number of negative number in each of the sublist.
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count=0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]<0:
                    count+=1
        return count     #Return the number of negative numbers in grid.        
