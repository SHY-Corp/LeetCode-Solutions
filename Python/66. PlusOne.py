'''
66. Plus One

Given a large integer represented as an integer array, where each element is a digit of the integer. The 
digits are ordered from most significant to least significant in left-to-right order. The large integer 
does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
'''

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
	# Transforming the input array into a list of characters
        strs = [str(digit) for digit in digits]
	# Joining the characters into a string
        string = "".join(strs)
	# Transforming the string into an int and adding 1 to it
        value = int(string)
        value += 1
	# Converting the int back to an array and returning
        return [int(x) for x in str(value)]