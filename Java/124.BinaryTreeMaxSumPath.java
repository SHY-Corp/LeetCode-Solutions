/*
For the given binary tree one needs to find Maximum sum path,a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
Proposed Solution:
For each node there can be four ways that the max path goes through the node:
1. Node only
2. Max path through Left Child + Node
3. Max path through Right Child + Node
4. Max path through Left Child + Node + Max path through Right Child

The idea is to keep trace of four paths and pick up the max one in the end.
*/
/*
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    static int maxsum;
    public int maxPathSum(TreeNode root) {
        maxsum = Integer.MIN_VALUE;
        int x = getSum(root);
        return maxsum;
    }
    public static int getSum(TreeNode root)
    {
        if(root == null)
        return 0;
        int ls = getSum(root.left);
        int rs = getSum(root.right);
        int sidemax = Math.max(ls,rs)+root.val;
        maxsum = Math.max(Math.max(maxsum,sidemax),Math.max(ls+rs+root.val,root.val));
        return Math.max(sidemax,root.val);
    }
}