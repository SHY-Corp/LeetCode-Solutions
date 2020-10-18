'''
PROBLEM: Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5

Problem link : https://leetcode.com/problems/length-of-last-word/
'''

'''
APPROACH -
We can convert string into list of words and can calculate length using reverse indexing
'''

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s.split()
        if (len(a)>=1):
            return len(a[-1])
        else:
            return 0
