# 1480. Running Sum of 1d Array
# Author- @lashewi

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        answer_arr = []
        sum_total = 0
        
        for i in range(0,len(nums)):
            sum_total += nums[i]
            answer_arr.append(sum_total)
                
        return answer_arr
