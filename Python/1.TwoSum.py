class Solution:
    """
    This code takes a list and returns 
    indices of the two numbers such that they add up to target 
    """
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashes = dict()
        for l, num in enumerate(nums):
            index = target - num
            if index not in hashes:
                hashes[num] = l
            else:
                return [hashes[index], l]
