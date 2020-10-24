'''
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
'''

class Solution(object):
    def threeSumClosest(self, nums, target):
        m = 20000
        l = len(nums)
        for i in range(0, l-2):
            for j in range(i+1, l-1):
                for k in range(j+1, l):
                    s = nums[i] + nums[j] + nums[k]
                    diff = abs(s-target)
                    if m>diff:
                        m = diff
                        closest_sum = s
        return(closest_sum)