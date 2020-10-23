# This program converts the entered roman number to integer .
# We have used the dictionary to ease the input for the desired roman representation of an integer.


class Solution(object):
    def romanToInt(self, s):

        number = 0
        counter = 0
        romandict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        list = ['I', 'V', 'X', 'L', 'C', 'D', 'M']
        for i in range(len(s) - 1):
            if list.index(s[i]) < list.index(s[i + 1]):
                number += romandict.get(s[i + 1])
                number -= romandict.get(s[i])
                counter += 1
            else:
                if list.index(s[i]) > list.index(s[i - 1]) and i != 0:
                    continue
                else:
                    number += romandict.get(s[i])
                    counter += 1
        if list.index(s[len(s) - 1]) > list.index(s[len(s) - 2]):
            return number
        else:
            number += romandict.get(s[len(s) - 1])
            return number
