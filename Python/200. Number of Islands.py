""" Problem - 200. Number of Islands

Problem statement -
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.




Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.


Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3



//Solution
Explaination:
In the grid, we need to record 1 peice of information of one point, grid[i][j], i.e., if grid[i][j] has been visited or not.
We initialize the check matrix with all False. It means none of elements in check matrix has been visited.
If one point grid[i][j] has not been visited, check[i][j] == False, it means we haven't count this point into one islands.
If one point grid[i][j] has been visited, check[i][j] == True, it means we already count this point into one islands.

Search function:
Each time you call search function, the search function will end until all the neighbors of grid[i][j] have value "1" been visited, i.e., those points are labeled True in check matrix.

Example:
grid = [ 1 ,  1 ,  1,
         1,   1,   0,
         0,   0,   1]

Intial check:
check = [ False, False, False,
        False, False, False,
        False, False, False]
# the first time call  search function:
grid[0][0] == '1' and check[0][0] == False:
check = [ True, True, True,
        True, True, False,
        False, False, False ]
count = 1
# the second time call check function:
grid[2][2] = '1' and check[2][2] == False:
check = [ True, True, True,
        True, True, False,
        False, False, True]
Count = 2
search function takes one point as input.
"""

# BFS Code

from collections import deque


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        count = 0
        check = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1' and check[i][j] == False:
                    count += 1
                    self.search(grid, check, i, j)
        return count

    def search(self, grid, check, i, j):
        qu = deque([(i, j)])
        while qu:
            i, j = qu.popleft()
            if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] == '1' and check[i][j] == False:
                check[i][j] = True
                qu.extend([(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)])


# DFS Code

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    print(i, j)
                    self.dfs(grid, i, j)
                    count += 1
        # print(grid)
        return count

    # use a helper function to flip connected '1's to 0

    def dfs(self, grid, i, j):
        grid[i][j] = 0
        for dr, dc in (1, 0), (-1, 0), (0, -1), (0, 1):
            r = i + dr
            c = j + dc
            if 0 <= r < len(grid) and 0 <= c < len(grid[0]) and grid[r][c] == '1':
                self.dfs(grid, r, c)
