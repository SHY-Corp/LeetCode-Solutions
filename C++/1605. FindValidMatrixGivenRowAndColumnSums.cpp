/*
PROBLEM - 1605. Find Valid Matrix Given Row and Column Sums

DESCRIPTION -

You are given two arrays rowSum and colSum of non-negative integers where
rowSum[i] is the sum of the elements in the ith row and colSum[j] is
the sum of the elements of the jth column of a 2D matrix.
In other words, you do not know the elements of the matrix, but you do know
the sums of each row and column.
Find any matrix of non-negative integers of size rowSum.length x colSum.length
that satisfies the rowSum and colSum requirements.

Return a 2D array representing any matrix that fulfills the requirements.
It's guaranteed that at least one matrix that fulfills the requirements exists.

CONSTRAINTS-

1 <= rowSum.length, colSum.length <= 500
0 <= rowSum[i], colSum[i] <= 108
sum(rows) == sum(columns)

APPROACH-

-- In this solution, we greedily choose either rowSum or colSum and add it to
   our ans array as well as update the rowSum and colSum array accordingly.
-- Everytime we choose the min(rowSum[i],colSum[j]) where i and j are the row
   number and column number respectively.

TIME COMPLEXITY-

TC of solution O(n.m) where n is number of rows and m is the number of columns.

*/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size())); // Answer array of size (n.m) i.e size of rowSum and colSum.
        for (int i = 0; i < rowSum.size(); i++) // For each element in answer array.
        {
            for (int j = 0; j < colSum.size(); j++)
            {
                ans[i][j] = min(rowSum[i], colSum[j]); // Populate the ans array.
                rowSum[i] -= ans[i][j]; // Updating the row and column sums.
                colSum[j] -= ans[i][j];
            }
        }
        return ans;
    }
};