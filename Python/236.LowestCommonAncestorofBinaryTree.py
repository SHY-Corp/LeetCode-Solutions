"""
Problem: Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two 
nodes p and q as the lowest node in T that has 
both p and q as descendants (where we allow a node to be a 
descendant of itself).”
"""
#function lowestCommonAncestor return the LCA of the given nodes
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # found the lca
        if root==None or root==p or root==q:
            return root
        # recursively call left and right children
        left=self.lowestCommonAncestor(root.left,p,q)
        right=self.lowestCommonAncestor(root.right,p,q)
        # this root is lca
        if left and right:
            return root
        if left==None and right==None:
            return None
        # root in left
        if left: 
            return left
        # root in right
        return right
