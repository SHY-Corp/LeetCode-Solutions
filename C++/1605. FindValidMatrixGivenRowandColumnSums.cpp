/*
    Problem Statement:
    You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

    Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

    Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.


    Problem Link:
    https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

    Approach:
    For every Value in the matrix, assign it to the minimum of rowSum, colSum.
    Subtract that value from rowSum and colSum and continue the procedure.
    Approach is quite intuitive and greedy.
*/


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> matrix(n,vector<int>(m,0));
        if(!n) return matrix;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = min(rowSum[i], colSum[j]);
                
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }
        
        return matrix;
    }
};