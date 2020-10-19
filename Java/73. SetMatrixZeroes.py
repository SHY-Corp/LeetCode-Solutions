#Given an m x n matrix. If an element is 0, set its entire row and column to 0
#Below is a Constant-space solution of the problem
#Time complexity-O(mn) Space complexity-O(m+n)


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m,n = len(matrix) , len(matrix[0])
        
        for i in range(m):   #using nested for loops 
            for j in range(n):
                if matrix[i][j] == 0: #if the current cell val is 0 we update the first val of that row or col
                    matrix[i][0] = 0
                    matrix[0][j] = 0
                    
        for i in range(m):
            for j in range(n):
                if matrix[i][0] == 0 or matrix[0][j]== 0:  #here we check either the first row or first col of that cell is 0 
                    matrix[i][j] = 0                       # if so, we update the value
                
