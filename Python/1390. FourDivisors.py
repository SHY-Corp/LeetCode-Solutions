"""
Problem: Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.

        If there is no such integer in the array, return 0.
"""
#function sumFourDivisors takes an integer list and returns the sum of divisors of all the numbers in the list with exactly four divisors.
import math
class Solution:
    def sumFourDivisors(self, nums):
        divisors=list()
        n=0
        for i in range(0,len(nums)):
            for j in range(1,(int(math.sqrt(nums[i]))+1)):
                if nums[i]%j==0:
                    n=n+1
                    divisors.append(j)
                    if n==1:
                        cur=len(divisors)
                    if j!=int(nums[i]/j):
                        divisors.append(nums[i]/j)  
                        n=n+1
                if n>4:
                    divisors=divisors[:cur-1]
                    n=0
                    break    
            if n>0 and n<4:
                divisors=divisors[:cur-1]
                n=0
            n=0
        return int(sum(divisors))