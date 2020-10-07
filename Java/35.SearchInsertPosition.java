class Solution {
	/*
		Link: https://leetcode.com/problems/search-insert-position/
		Problem: 
		Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

		Example 1:

		Input: nums = [1,3,5,6], target = 5
		Output: 2
		Example 2:

		Input: nums = [1,3,5,6], target = 2
		Output: 1
		Example 3:

		Input: nums = [1,3,5,6], target = 7
		Output: 4
		Example 4:

		Input: nums = [1,3,5,6], target = 0
		Output: 0
		Example 5:

		Input: nums = [1], target = 0
		Output: 0

		Constraints:
		1 <= nums.length <= 104
		-104 <= nums[i] <= 104
		nums contains distinct values sorted in ascending order.
		-104 <= target <= 104

		Solution:
		Use binary search to find if target in in given sorted array.
		If target is found, return mid.
		After loop exit, check value of low.
		If low is equal to length of the array, it means that target is not found and it is definitely bigger than last element in the array. So, return low.
		If value at index low is lower than target, return low+1
		Else, return low.

		Time Complexity: O(log(n)) where n is size of the array
		Space Complexity: O(1)
	*/
    public int searchInsert(int[] nums, int target) {
        
        int low = 0;
        int high = nums.length;
        int mid = (low+high)/2;
        
        while(low<high)
        {
            mid = (low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        if(low==nums.length)
        {
            return low;
        }
        
        if(nums[low]<target)
        {
            return low+1;
        }
        
        return low;
        
    }
}