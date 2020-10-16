# Problem link: https://leetcode.com/problems/maximum-binary-tree/
#
# Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
# 1.The root is the maximum number in the array.
# 2.The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
# 3.The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        if len(nums) > 0:
            max_elem = max(nums)
            max_pos = nums.index(max_elem)
            nums.remove(max_elem)
            return TreeNode(max_elem,
                            self.constructMaximumBinaryTree(nums[:max_pos]),
                            self.constructMaximumBinaryTree(nums[max_pos:]))
        return None