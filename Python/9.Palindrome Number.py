#This program returns true if the number is a palindrome, else it returns false

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        #All negative numbers reutrn false for Palindrome
        if x < 0:
            return False
        
        a = x
        sum = 0
        while a > 0 :
            r = a % 10
            sum = sum*10 + r
            a = a // 10
        #If reversed number is same as orignal, returns True
        if sum==x:
            return True
        
        #else returns false
        else:
            return False
