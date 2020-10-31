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

Solution : Insert the non-zero number first, then insert the zeroes.
*/

public class Solution{
    public void moveZeroes(int[] nums){
        int index=0;
        for (int i=0;i<nums.length;i++){
            if (nums[i]!=0) nums[index++]=nums[i];
        }
        while(index<nums.length){
            nums[index++]=0;
        }
    }
}