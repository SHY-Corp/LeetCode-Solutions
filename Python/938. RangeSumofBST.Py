# Approach : 1) Inorder traversal (DFS) and range(Time complexity= O(H)(h is height of the tree)



#Solution : Inorder traversal and range(DFS)
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        output=[]
        self.inorder(root,output)
        sum=L+R
        for i in range(len(output)):
            if output[i]>L and output[i]<R:
                sum+=output[i]
        return sum
    def inorder(self,root,output):
        if root == None:
            return
        else:
            self.inorder(root.left,output)
            output.append(root.val)
            self.inorder(root.right,output)
