# Having one number num isUgly checks if the only prime divisors of num are 2, 3 and 5.
class Solution(object):
    def isUgly(self, num):
        if num == 0:
            return False
        while num % 2 == 0:
            num /= 2
        while num % 3 == 0:
            num /= 3
        while num % 5 == 0:
            num /= 5
        return num == 1
            