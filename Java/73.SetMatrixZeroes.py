#Below is a constant space solution of the problem
#Time complexity-O(mn) Space complexity-O(m+n)
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m,n = len(matrix) , len(matrix[0])
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
                    
        for i in range(m):
            for j in range(n):
                if matrix[i][0] == 0 or matrix[0][j]== 0:
                    matrix[i][j] = 0
                
