class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        res = right = 0
        intervals.sort(key=lambda a: (a[0],-a[1]))
        
        for i,j in intervals:
            res += j > right
            right = max(right,j)
        return res
        
