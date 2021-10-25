/*
    542. 01 Matrix

    Given a matrix, each item can only be 0s or 1s. The objective is to change the 1 cells into the distance
    to the nearest 0 cell.

    Mark every non-zero cells as a super huge number.
    For every single cell, if it is not 0, we do BFS to find the nearest 0. rinse and repeat for every cell.
*/

class Solution {
   public:
    const int MAX_DIST = 10000;
    // returns distance to 0
    int findDistance(vector<vector<int>>& matrix, int c, int r) {
        if (r >= matrix[0].size() || c >= matrix.size() ||
            r < 0 || c < 0) {
            return MAX_DIST;
        } else if (matrix[c][r] == -1) {
            // we know the above is not true, we need this to not have seg fault
            return MAX_DIST;
        } else if (matrix[c][r] == 0 || matrix[c][r] == 1) {
            return matrix[c][r];
        }

        int current = matrix[c][r];
        matrix[c][r] = -1;  // mark as visited before we compute remaining
        int left = 1 + findDistance(matrix, c, r - 1);
        int right = 1 + findDistance(matrix, c, r + 1);
        int up = 1 + findDistance(matrix, c - 1, r);
        int down = 1 + findDistance(matrix, c + 1, r);
        matrix[c][r] = min(current, min(min(left, right), min(up, down)));

        return matrix[c][r];
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        for (int c = 0; c < matrix.size(); c++) {
            for (int r = 0; r < matrix[c].size(); r++) {
                if (matrix[c][r] == 1) {
                    matrix[c][r] = MAX_DIST;
                }
            }
        }

        for (int c = 0; c < matrix.size(); c++) {
            for (int r = 0; r < matrix[c].size(); r++) {
                if (matrix[c][r] != 0) {
                    findDistance(matrix, c, r);
                }
            }
        }
        return matrix;
    }
};