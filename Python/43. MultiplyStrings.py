"""
Leetcode's Medium challege #43 - Multiply Strings (Solution)
<https://leetcode.com/problems/multiply-strings/>

Description:

Given two non-negative integers num1 and num2 
represented as strings, return the product of num1 and num2, 
also represented as a string.

EXAMPLE:

Input: num1 = "2", num2 = "3"
Output: "6"

Author: <Curiouspaul1>
github: https://github.com/Curiouspaul1

"""


def int_(s):
    """
    Converts strings to int, raises exception
    for non-int literals
    """
    reslt = 0
    for i in s:
        if ord(i) in range(48,58):  # checks that string character is something in [0-9]
            reslt = reslt*10 + (ord(i) - ord('0'))
        else:
            raise ValueError
    return reslt

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if len(num1) >= 110 or len(num2) >= 110:    # constraints from leetcode
            return 0
        try:
            num1, num2 = int_(num1), int_(num2)
            result = num1 * num2
            return str(result)
        except ValueError:
            print("Invalid Entry")
            return 0