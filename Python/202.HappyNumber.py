# Return True if n is a happy number, and False if not.

# Example:

# Input: 19
# Output: true
# Explanation:
# 12 + 92 = 82
# 82 + 22 = 68
# 62 + 82 = 100
# 12 + 02 + 02 = 1


class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        result = 0
        while n > 10:
            slicedDigit = n % 10
            n = int(n / 10)
            result += slicedDigit ** 2
            if n < 10:
                result += n ** 2
        while n >= 10:
            slicedDigit = n % 10
            n = int(n / 10)
            result += slicedDigit ** 2
            if n < 10:
                result += n ** 2

        if result != 1:
            self.isHappy(result)

        if n == 1:
            return True
        else:
            return False


def main():
    testSolution = Solution()
    print(testSolution.isHappy(19))


main()
