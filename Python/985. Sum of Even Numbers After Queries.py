''' 
985. Sum of Even Numbers After Queries
https://leetcode.com/problems/sum-of-even-numbers-after-queries/

You are given an integer array nums and an array queries where queries[i] = [vali, indexi].

For each query i, first, apply nums[indexi] = nums[indexi] + vali, then print the sum of the even values of nums.

Return an integer array answer where answer[i] is the answer to the ith query.
'''
class Solution:
    def sumEvenAfterQueries(self, nums, queries):
        arr_sum = 0
        res = []
        # Calculate the initial sum of the even values in the array
        for num in nums:
            if num % 2 == 0:
                arr_sum += num
        
        for query in queries:
            # If the value on which query is being performed is even remove value from sum of the array
            if nums[query[1]] % 2 == 0:
                arr_sum -= nums[query[1]]
            # Perform the specified query
            nums[query[1]] += query[0]
            # If the value after the query is even add the value back to sum of array
            if nums[query[1]] % 2 == 0:
                arr_sum += nums[query[1]]
            # Append the resulting arr_sum after the query has been performed
            res.append(arr_sum)
        return res
            