class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x>0:
            n = x
        else:
            n = -x
        c = 0
        
        while n>0:
            r = n % 10
            c = c*10 + r
            n = n // 10
        
        if c>((2**31)-1):
            c=0
       
        if x>0:
            return c
        else:
            return -c
