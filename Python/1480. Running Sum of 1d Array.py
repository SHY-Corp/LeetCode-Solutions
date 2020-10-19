class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        b = []
        sum = 0 
        for i in nums:
            sum += i
            b.append(sum)
        return b
