#A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
#Now given an M x N matrix, return True if and only if the matrix is Toeplitz.

class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        c = True
        rows = len(matrix)
        cols = len(matrix[0])
        
        for x in range(rows):
            for y in range(cols):
                if x != 0 and y != 0: 
                    if matrix[x][y] != matrix[x-1][y-1]:
                        c = False
                        break
        if c == False:
            return False
        else:
            return True 
