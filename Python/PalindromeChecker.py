#Statement: This program takes a string as input, checks whether the string is a palindrome or not and returns,
#  True if yes and returns False if no.

# For example: "AABBCCBBAA" is a palindrome, so True will be returned.
# "122333221" is again a palindrome, so True will be returned.
# But, "I am a good code" is not a palindrome, so False will be returned.

class Solution(object):
    def palindromeChecker(self, str):
        """
        :type str: string
        :rtype: boolean
        """
        strLower = str.lower()  # converts the string into lower case
        strList = strLower.split("")  # converting the string into a list
        strReverse = strList.reverse()  # reversing the list
        finalStr = "".join(strReverse)  # getting the final reversed string

        if finalStr == str:  # This part checks if the final reversed string is eqaul to the original string or not.
            return True 

        else:
            return False
        



