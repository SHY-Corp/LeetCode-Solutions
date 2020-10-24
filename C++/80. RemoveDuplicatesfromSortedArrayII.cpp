/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.

Example 1: 
    Input: nums = [1,1,1,2,2,3]
    Output: 5, nums = [1,1,2,2,3]

Example 2:
    Input: nums = [0,0,1,1,1,1,2,3,3]
    Output: 7, nums = [0,0,1,1,2,3,3]
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // postion where we have to insert new element
        int pos = 0;
        
        //iterating over all the elements of the array
        for (int n : nums) {     
        // First conditon allows inserting the first two elements of the array as it is because we are allowing 2 duplicates or array of size 2
        // Second condition allows inserting of the new element only when the new element is greater than the element at the second last from the current position
            if (pos < 2 || n > nums[pos-2]) 
                nums[pos++] = n;
        } 
        return pos;     
    }
};
