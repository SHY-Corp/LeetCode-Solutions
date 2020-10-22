/*
283 | MOVE ZEROES | EASY PROBLEM

Problem Description:
Given an array of integers, move all the 0's to the end of the array, while
maintaining the relative order of elements and doing this operation in-place

Conditions:
1. Preserve relative order
2. In place operation

Optimization Criteria:
1. Minimize extra space taken(no copy of the array allowed)
2. Minimize operations

Solution Explained: Two Pointer Solution
Maintain two pointers 'nz' and 'z' to track the last position of non zero element
and traverse through the array, respectively. The pointer 'nz' is initialised
at 0th index as all non zero elements must start from here.
As you traverse through the array, from left to right, using the pointer 'z',
two things can happen:
  1. You encounter a 0 element:
    Skip it; no operation performed
    This is because we may
  2. You encounter a non zero element:
    In this case, you must swap the values at indez 'z' and 'nz' because 'nz'
    represents the last valid position of the non zero element. Increement the
    value of 'nz' i.e, increement it's value by 1 to move it to the right.
    Continue traversing the array using 'z'.
*/

class Solution {
  public:
      void moveZeroes(vector<int>& A) {
          //to track the last position in the array of non zero elements to the left
          int nz=0;

          for(int z=0;z<A.size();z++){
              if(A[z]!=0){
                  int t=A[z];
                  A[z]=A[nz];
                  A[nz]=t;
                  nz++;
              }
          }
      }
};
