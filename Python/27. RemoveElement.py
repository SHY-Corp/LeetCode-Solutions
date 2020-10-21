# Given an array nums and a value val, remove all instances of that value in-place and return the new length.
# Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
# The order of elements can be changed. It doesn't matter what you leave beyond the new length.

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        '''
        ignore target element and arrange every other element on starting (n - m) indices, where
        n is number of elements in array and m is number of occurrences of target element
        '''
        final_index = 0                     # to decide indices of elements in final list
        items = 0                           # modified list's number of values
        for index in range(len(nums)):
            if nums[index] != val:
                nums[index], nums[final_index] = nums[final_index], nums[index]
                final_index += 1
                items += 1
        return items