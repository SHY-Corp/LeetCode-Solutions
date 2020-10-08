# Given a string, find the first non-repeating character in it and return its index. 
# If it doesn't exist, return -1.

class Solution:
    def firstUniqChar(self, s: str) -> int:
        counts = {}

        # Iterate through array once, adding counts to dictionary
        for char in s:
            if char in counts:
              counts[char] += 1
            else:
              counts[char] = 1

        # Iterate through array again, finding the first a letter with a count of 0
        for index, char in enumerate(s):
            if counts[char] == 1:
                return index
        return -1