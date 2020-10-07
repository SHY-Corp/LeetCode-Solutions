#Function convertToBase7 converts number num to string representing this number in base 7.
class Solution(object):
    def convertToBase7(self, num):
        if num == 0:
            return "0"
        digitsList = []
        sign = num//abs(num)
        num = abs(num)
        while num > 0:
            digitsList += [str(num % 7)]
            num //= 7
        digitsList.reverse()
        numberBase7 = "".join(digitsList)
        if sign == -1:
            return "-" + numberBase7
        return numberBase7