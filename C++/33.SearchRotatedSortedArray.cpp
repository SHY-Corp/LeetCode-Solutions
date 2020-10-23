/*Leetcode Problem 33 - Medium level

You are given an integer array nums sorted in ascending order, and an integer target.
Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
If target is found in the array return its index, otherwise, return -1.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are "unique".
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1 && nums[0] == target)
            return 0;
        
        //find the pivot point i.e., point where the array is no longer sorted
        int left = 0, right = nums.size()-1;
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[right])
                left = mid+1;
            else
                right = mid;
        }
        
        int start = left;
        left = 0;
        right = nums.size()-1;
        
        if(target >= nums[start] && target <= nums[right])
            left = start;
        else
            right = start;
        
        while(left <=right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        
        return -1;
    }
};

