"""This program takes a matrix of size mxn as input, and prints the matrix in a spiral format
for example: input ->> [[1,2,3],
                        [4,5,6],
                        [7,8,9],
                        [10,11,12]]
             output ->> 1 2 3 6 9 12 11 10 7 4 5 8"""


class Solution:
    def matrix_spiral(self, matrix):
        """
        :type matrix: list[list[]]
        """

        starting_row = 0
        ending_row = len(matrix)
        starting_col = 0
        ending_col = len(matrix[0])
        while starting_row < ending_row and starting_col < ending_col:
            for k in range(starting_col, ending_col):
                print(matrix[starting_row][k], end=" ")
            starting_row += 1
            for k in range(starting_row, ending_row):
                print(matrix[k][ending_col-1], end=" ")
            ending_col -= 1
            if starting_row < ending_row:
                for k in range(ending_col-1, starting_col-1, -1):
                    print(matrix[ending_row-1][k], end=" ")
                ending_row -= 1
            if starting_col < ending_col:
                for k in range(ending_row-1, starting_row-1, -1):
                    print(matrix[k][starting_col], end=" ")
                starting_col += 1
