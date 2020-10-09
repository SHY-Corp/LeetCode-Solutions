class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return len([nums[i] for i in range(len(nums)) if (len(str(nums[i])) % 2 == 0 )])