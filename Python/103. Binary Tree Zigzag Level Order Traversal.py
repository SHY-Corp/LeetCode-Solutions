# Definition for a binary tree node.

# class TreeNode:

#     def __init__(self, val=0, left=None, right=None):

#         self.val = val

#         self.left = left

#         self.right = right

class Solution:

    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:

        curr = [root] if root else None

        levels, zig = [], True

        while curr:

            level = [node.val for node in (curr if zig else reversed(curr))]

            levels.append(level)

            next_ = []

            for node in curr:

                if node.left: next_.append(node.left)

                if node.right: next_.append(node.right)

            curr = next_

            zig = not zig

        return levels
