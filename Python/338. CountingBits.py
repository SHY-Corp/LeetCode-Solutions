"""
Problem:
--------

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num
calculate the number of 1's in their binary representation and return them as an array.
"""


from typing import List

class Solution:
    def countBits(self, num: int) -> List[int]:
        # Loop from 0 to num, convert them in binary and use
        # `count()` to count the occurances of 1.

        result = [bin(i).count('1') for i in range(num + 1)]
        return result
