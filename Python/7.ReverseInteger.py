#This program takes in a number, reverses it and then returns it as the output.

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        #get positive number irrespestive of the original sign
        if x>0:
            n = x
        else:
            n = -x
        c = 0
        
        while n>0:
            r = n % 10
            c = c*10 + r
            n = n // 10
        
        #reset value to 0 if answer exceeds the constraint
        if c>((2**31)-1):
            c=0
       
        #return the answer with the original sign
        if x>0:
            return c
        else:
            return -c
