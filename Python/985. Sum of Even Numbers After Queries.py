# https://leetcode.com/problems/sum-of-even-numbers-after-queries/
class Solution:
    def sumEvenAfterQueries(self, nums, queries):
        arr_sum = 0
        res = []
        for num in nums:
            if num % 2 == 0:
                arr_sum += num
        
        for query in queries:
            if nums[query[1]] % 2 == 0:
                arr_sum -= nums[query[1]]
            nums[query[1]] += query[0]
            if nums[query[1]] % 2 == 0:
                arr_sum += nums[query[1]]
            res.append(arr_sum)
        return res
            