'''
Problem link: https://leetcode.com/problems/split-a-string-in-balanced-strings/

idea:
1. Initialize a counter variable and result variable: count, result
2. Loop from left to right
3. if we found 'R', subtract 1 from count
4. if we found 'L', add 1 to count
5. if the count become 0, we know that the substring already balanced, thus result + 1
6. return result
'''

class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        result = 0
        for char in s:
            if 'L' == char:
                count += 1
            else:
                count -= 1
            
            if count == 0:
                result += 1
        return result
 
