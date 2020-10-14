# Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.
# A subarray is a contiguous subsequence of the array.
# Return the sum of all odd-length subarrays of arr.
# Author- @lashewi

class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        res = 0
		
        for i in range(n):
            even_away = ((i // 2) + 1) * ((n - i - 1) // 2 + 1)
            odd_away = ((i + 1) // 2) * ((n - i) // 2)
            res += arr[i] * (even_away + odd_away)
            
        return res
