class Solution:
    """
    This program takes a list and returns 
    indices of the two numbers such that they add up to target 
    """
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashes = dict()
        for i, num in enumerate(nums):
            index = target - num
            if index not in hashes:
                hashes[num] = i
            else:
                return [hashes[index], i]