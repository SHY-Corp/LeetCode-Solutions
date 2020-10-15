/*
Non-decreasing Array-
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

Problem link- https://leetcode.com/problems/non-decreasing-array/

Approach-
If the array is already non-decreasing, return true
If the array is non-decreasing, check the following to cases
Case 1: Change the next element to the current element and check if non-decreasing
    Eg: For [1,4,2,3] change 2 to 4 to get [1,4,4,3]
Case 2: Change the current element to the next element and check if non-decreasing
    Eg: For [1,4,2,3] change 4 to 2 to get [1,2,2,3]

If both cases return false, then the array cannot be transformed to a non-decreasing array using only 1 change
If at least 1 case returns true, array can be transformed
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int counter=0;          //checks if nums is non-decreasing
        int n=nums.size();
        vector<int> case1=nums;
        vector<int> case2=nums;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                counter++;
                case1[i+1]=nums[i];
                case2[i]=nums[i+1];
                break;
            }
        }
        bool flag1=0, flag2=0;

        for(int i=0;i<n-1;i++)
        {  
            if(case1[i+1]<case1[i])
                flag1=1;                //case 1 is not non-decreasing
            if(case2[i+1]<case2[i])
                flag2=1;                //case 2 is not non-decreasing
            if(flag1 && flag2)
                break;
        }

        if(counter==0)
            return true;
        else if(flag1 && flag2)
            return false;
        else
            return true;
    }
};