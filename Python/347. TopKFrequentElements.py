# 347. Top K Frequent Elements (https://leetcode.com/problems/top-k-frequent-elements/)

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        frequencies = {}
        for num in nums:
            if num in frequencies:
                frequencies[num] = frequencies[num] + 1
            else:
                frequencies[num] = 1
        
        keys = []
        while len(keys) < k:
            maxx = None
            keyy = None
            for key, value in frequencies.items():
                if not maxx:
                    keyy = key
                    maxx = value
                    continue
                if value > maxx:
                    maxx = value
                    keyy = key
            keys.append(keyy)
            frequencies.pop(keyy)
        return keys
                
