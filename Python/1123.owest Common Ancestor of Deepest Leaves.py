	def subtreeWithAllDeepest(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        return self.dfs(root)[1]
    
    def dfs(self, root):
        if not root:
            return 0, None
        
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        
        if left[0] > right[0]:
            return left[0] + 1, left[1]
        elif left[0] < right[0]:
            return right[0] + 1, right[1]
        else:
            return left[0] + 1, root
