"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    # calculate n-ary Tree depth
    def maxDepth(self, root: 'Node') -> int:
        # if root not exist than return 0
        if root == None:
            return 0
        # if root have't children than return 0
        if root.children == None:
            return 1
        # get max depth in root's children
        M = 0
        for child in root.children:
            M = max(M,self.maxDepth(child))
        # add this root
        return M+1