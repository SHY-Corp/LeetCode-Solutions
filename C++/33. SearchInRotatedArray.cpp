/*
PROBLEM: You are given an integer array nums sorted in ascending order, and an integer target.
Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
If target is found in the array return its index, otherwise, return -1.

APPROACH: Searching using modified binary search.

*/




class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ptr1=0,ptr2=nums.size()-1;
        while(ptr1<=ptr2){
            int mid=ptr1+(ptr2-ptr1)/2;
            if(nums[mid]==target) return mid;
            else if(target>nums[mid] && nums[mid]<=nums[ptr2] && target>nums[ptr2]){
                ptr2=mid-1;
            }
            else if(target<nums[mid] && nums[mid]>=nums[ptr1] && target<nums[ptr1]){
                ptr1=mid+1;
            }
            else if(nums[mid]>target) ptr2=mid-1;
            else ptr1=mid+1;
        }
        return -1;
    }
};
