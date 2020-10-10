"""
Given an integer n, return the number of trailing zeroes in n!.

Example
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
"""

# Algorithm explained:
#   In the expanded form of facotorial, the occurenses of 5 or its multiples
# contribute to the trailing zeroes. So, first we count the multiples of 5,
# and now we account for the powers of 5, which can be written as
# repeated multiplication of 5 (eg: 25 = 5 x 5, this contributes 2 zeroes),
# so we scale the number down by 5 (eg: 25 beomes 5) and repeat the same
# procedure until there are no multiples of 5.


class Solution:
    def trailingZeroes(self, n: int) -> int:
        if n < 5:
            return 0
        a = n // 5
        return a + self.trailingZeroes(a)
