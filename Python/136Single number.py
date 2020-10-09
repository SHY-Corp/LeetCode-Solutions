from collections import Counter
class Solution(object):
    def singleNumber(self, nums):
        c=Counter(nums)
        sorted_items=sorted(c.items(), key = lambda x:x[1])
        return sorted_items[0][0]
        