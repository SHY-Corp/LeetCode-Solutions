# Problem link: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

# In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.
# (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
# We may rotate the ith domino, so that A[i] and B[i] swap values.
# Return the minimum number of rotations so that all the values in A are the same, 
# or all the values in B are the same.
# If it cannot be done, return -1.

# Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
# Output: 2
# Explanation: 
# The first figure represents the dominoes as given by A and B: before we do any rotations.
# If we rotate the second and fourth dominoes, 
# we can make every value in the top row equal to 2, as indicated by the second figure.

'''
Approach:
Figure out if any one particular number is present on either side of each dice.
Compute minimum rotations required.
'''
class Solution:
    def minDominoRotations(self, a: List[int], b: List[int]) -> int:
        size = len(a)
        x,y = None,None
        if all([a[0] in (a[i], b[i]) for i in range(size)]):
            x = min(size-a.count(a[0]), size - b.count(a[0]))
        elif all([b[0] in (a[i], b[i]) for i in range(len(b))]):
            y = min(size-a.count(b[0]), size - b.count(b[0]))
        # print(x,y)
        if x is None:
            if y is None:
                return -1
            else:
                return y
        else:
            if y is None:
                return x
            else:
                return min(x,y)