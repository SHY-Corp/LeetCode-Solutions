"""Approach : 

Added all the Roman symbols with its representing values to a dictionary in a descending order.
Then loop over the dictionary and as many of the largest values that can be found in the number to the roman string and leave the remaining part of the number to the smaller symbol."""

class Solution:
    def intToRoman(self, num: int) -> str:
        symbol_value = {"M":1000, "CM":900, "D":500, "CD":400, "C":100, "XC":90, "L":50, "XL":40, "X":10, "IX":9, "V":5 , "IV":4 , "I":1}
        roman = ""
        for i in symbol_value:
            roman += i*(num//symbol_value[i])
            num = num%symbol_value[i]
        return roman