""" Problem - 51. N-Queens

Problem statement -
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a
queen and an empty space respectively.


Example :

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.



//Solution
In this problem, we can go row by row, and in each position, we need to check if the column, the 45° diagonal and the 135° diagonal had a queen before.

"""


class Solution(object):
    def solveNQueens(self, n):
        def dfs(r):
            if r == n:
                res.append([''.join(row) for row in b])
                return
            for c in xrange(n):
                if isValid(r, c):
                    b[r][c] = 'Q'
                    dfs(r + 1)  # fill row by row
                    b[r][c] = '.'

        def isValid(r, c):
            for i in xrange(r):
                for j in xrange(n):
                    if b[i][j] == 'Q' and (c == j or  # same column
                                           i + j == r + c or  # 45 degree line
                                           i - j == r - c):  # 135 degree line
                        return False
            return True

        b = [['.'] * n for _ in xrange(n)]
        res = []
        dfs(0)  # start from row 0
        return res
