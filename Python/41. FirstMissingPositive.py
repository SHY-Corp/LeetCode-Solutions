'''
    LeetCode Link: https://leetcode.com/problems/first-missing-positive/

    Given an unsorted integer array nums, find the smallest missing positive integer.

    Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?

    Example:

        Input: nums = [0,1,2]
        Output: 3

        Input: nums = [3,4,-1,1]
        Output: 2

    Constraints:

        0 <= nums.length <= 300
        -231 <= nums[i] <= 231 - 1

    Solution: 
        
        Step 1: Check if 1 is present in nums, else return 1
        Step 2: Try to make necessary changes to nums so as to use the elements as indices
        Step 3: Make the negative numbers as well as zero as 1 as they don't contribute to indices
        Step 4: Traverse the array, using values as indices, convert the values at those indices as negative
        Step 5: Check if any value is still positive, the index of that value is the answer
        Step 6: If no such value is there, return len(nums) + 1 as the answer


    Time Complexity: O(n)
    Space Complexity: O(1)

'''

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:

        n = len(nums)
        if n==0:
            return 1
        isone = 0
        for i,val in enumerate(nums):
            if val==1:
                isone = 1
            if val<=0 or val>n:
                nums[i] = 1
        if not isone:
            return 1
        for i,val in enumerate(nums):
            if nums[abs(val)-1]>0:
                nums[abs(val)-1] *= -1
        print(nums)
        for i,val in enumerate(nums):
            if val>0:
                return i+1
        return n+1
