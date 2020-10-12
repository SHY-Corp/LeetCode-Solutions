/*
 According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input:
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output:
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
 */


class Solution {
public:
    void gameOfLife(vector <vector<int>> &board) {

        int rows = board.size();
        int coloumn = board[0].size();


        // use this to initialise a new copy of the board
        vector <vector<int>> copy(board.begin(), board.end());


        // iterating through the grid to calculate the number of 'alive' neighbpurs a cell has in this generation
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < coloumn; j++) {
                // neighbour is a function that returns 1 if the adjacent call is alive or dead
                int surround = neighbour(copy, i + 1, j) + neighbour(copy, i - 1, j) + neighbour(copy, i, j + 1) +
                               neighbour(copy, i, j - 1) + neighbour(copy, i - 1, j - 1) +
                               neighbour(copy, i - 1, j + 1) + neighbour(copy, i + 1, j - 1) +
                               neighbour(copy, i + 1, j + 1);

                // If the cell is alive
                if (copy[i][j] == 1) {
                    // if the call has less than 2 neighbour the cell dies in the next generation
                    if (surround < 2) {
                        board[i][j] = 0;
                        continue;
                    }
                    // if the call has 2 or 3 neighbour , the cell remains alive in the next generation
                    if (surround == 2 || surround == 3) {
                        board[i][j] = 1;
                        continue;
                    }
                    // if the call has more than 3 neighbour then the cell dies in next generation
                    if (surround > 3) {
                        board[i][j] = 0;
                        continue;
                    }
                }

                // If the cell is dead
                if (copy[i][j] == 0) {
                    // if the cell has exactly 3 neighbour then bring back the cell to life in next generation
                    if (surround == 3) {
                        board[i][j] = 1;
                        continue;
                    }
                }

            }

        }


    }

    // this function returns 1 if the indices (i,j) have an alive neighbour or else it returns 0
    int neighbour(vector <vector<int>> &copy, int i, int j) {
        if (i < 0 || i >= copy.size() || j < 0 || j >= copy[0].size())
            return 0;
        if (copy[i][j] == 1) {
            return 1;
        }

        return 0;
    }
};