class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        xs = [tp[0] for tp in points]
        xs.sort()
        prev= xs[0]
        ans = 0
        for it in xs[1:]:
            ans = max(ans, it - prev)
            prev = it
        
        return ans
        
