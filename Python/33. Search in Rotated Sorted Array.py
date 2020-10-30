""" Problem - 33. Search in Rotated Sorted Array

You are given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.


Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guaranteed to be rotated at some pivot.
-10^4 <= target <= 10^4


Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1



//Solution
My solutions use binary search guided by the following thoughts:

Remember the array is sorted, except it might drop at one point.

If nums[0] <= nums[i], then nums[0..i] is sorted (in case of "==" it's just one element, and in case of "<" there must be a drop elsewhere). So we should keep searching in nums[0..i] if the target lies in this sorted range, i.e., if nums[0] <= target <= nums[i].

If nums[i] < nums[0], then nums[0..i] contains a drop, and thus nums[i+1..end] is sorted and lies strictly between nums[i] and nums[0]. So we should keep searching in nums[0..i] if the target doesn't lie strictly between them, i.e., if target <= nums[i] < nums[0] or nums[i] < nums[0] <= target

Those three cases look cyclic:

    nums[0] <= target <= nums[i]
               target <= nums[i] < nums[0]
                         nums[i] < nums[0] <= target
So I have the three checks (nums[0] <= target), (target <= nums[i]) and (nums[i] < nums[0]), and I want to know whether exactly two of them are true. They can't all be true or all be false (check it), so I just need to distinguish between "two true" and "one true".
"""


# without bisect

def search(self, nums, target):
    lo, hi = 0, len(nums) - 1
    while lo < hi:
        mid = (lo + hi) / 2
        if (nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]):
            lo = mid + 1
        else:
            hi = mid
    return lo if target in nums[lo:lo+1] else -1


# with bisect:

class Solution:
    def search(self, nums, target):
        self.__getitem__ = lambda i: \
            (nums[0] <= target) ^ (nums[0] > nums[i]) ^ (target > nums[i])
        i = bisect.bisect_left(self, True, 0, len(nums))
        return i if target in nums[i:i+1] else -1
