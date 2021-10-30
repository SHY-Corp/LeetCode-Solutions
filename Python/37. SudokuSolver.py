'''
37. Sudoku Solver

Given a Sudoku board this program solves the puzzle by filling the empty cells. (It is guaranteed that the 
puzzle is solveable and has only one solution)
'''
class Solution:
    '''
    This method checks if it is possible to put the 'n' in the yth row and xth column of the board
    '''
    def possible(self,y,x,n):
        for i in range(0, 9):
            if self.board[y][i] == n:
                return False        
        for i in range(0, 9):
            if self.board[i][x] == n:
                return False
        x0 = (x//3)*3
        y0 = (y//3)*3
        for i in range(0, 3):
            for j in range(0, 3):
                if self.board[y0+i][x0+j] == n:
                    return False
        return True
    '''
    This method solves the Sudoku problem using a backtracking approach, that is, it tries filling the board
    with a possible answer, if it doesn't work, it backtracks in the recursion stack and tries other possibilities
    until we solve the board. The strategy is better explained in this video: https://youtu.be/G_UYXzGuqvM
    '''
    def solve(self):
        for y in range(0,9):
            for x in range(0,9):
                if self.board[y][x] == ".":
                    for i in range(1,10):
                        if self.possible(y,x,str(i)):
                            self.board[y][x] = str(i)
                            if not self.solve():
                                self.board[y][x] = "."
                            else:
                                return True
                    return False
        return True
        
    def solveSudoku(self, board: List[List[str]]) -> None:
        self.board = board
        self.solve()
                            
                            
        
    
        