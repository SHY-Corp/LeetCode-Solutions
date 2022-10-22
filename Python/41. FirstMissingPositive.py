class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # The smallest positive number is 1, hence we set that
        smallest = 1
        while True:
            # We check if this number is present in nums, if it does we add 1 to the number
            if smallest in nums:
                smallest += 1
            else:
                # else we just return the previously computed smallest number
                return smallest
