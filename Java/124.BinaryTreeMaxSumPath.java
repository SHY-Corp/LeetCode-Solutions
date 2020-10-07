/**
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