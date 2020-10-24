"""

Given an array nums of n integers and an integer target, find three integers in nums such that the 
sum is closest to target. Return the sum of the three integers. You may assume that each input would 
have exactly one solution.


Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
"""

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        len_of_arr = len(nums)
        difference = 10**9
        nums.sort()
        for i in range(len_of_arr):
            if difference == 0:
                break
            low, high = i+1, len_of_arr - 1
            while low < high:
                # Since array is sorted, adding two small number with largest one,
                # hoping we would get close to target,
                # if not, there are two cases, the sum would be less than target,
                # then we need to shift the middle element to right for getting a 
                # a larger number,
                # if the sum is bigger than target, we need to shift the high index 
                # to left, for getting a smaller number. 
                sum_of_three = nums[i] + nums[low] + nums[high]
                if abs(target - sum_of_three) < abs(difference):
                    difference = target - sum_of_three
                if sum_of_three < target:
                    low += 1
                else:
                    high -= 1
        return target - difference

