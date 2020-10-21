/* 
  Given an array of integers A sorted in non-decreasing order,
  return an array of the squares of each number,
  also in sorted non-decreasing order.

  https://leetcode.com/problems/squares-of-a-sorted-array/

*/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        int len = A.size();
        vector<int> B(len);

        for (int i = 0; i < len; i++)
        {
            B[i] = A[i] * A[i];
        }

        sort(B.begin(), B.end());
        return B;
    }
};
