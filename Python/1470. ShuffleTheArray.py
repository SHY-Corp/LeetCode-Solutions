# 1470. Shuffle the Array
# Author- @lashewi

class Solution:

    def shuffle(self, nums: List[int], n: int) -> List[int]:
        out = []
        for i in range(n):
            out.append(nums[i])
            out.append(nums[i+n])
        return out
