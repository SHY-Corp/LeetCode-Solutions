/**
 * Question:
 * Given a binary tree, return the sum of values of nodes with even-valued grandparent.
 * (A grandparent of a node is the parent of its parent, if it exists.)
 * <p>
 * If there are no nodes with an even-valued grandparent, return 0.
 * <p>
 * Example:
 * Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * Output: 18
 * Explanation: i<sup>th</sup> node is the parent of (i + 1)<sup>th</sup> (i + 2)<sup>th</sup> node.
 * The nodes [x,x,x,2,7,1,3,x,x,x,x,x,x,x,5] are the nodes with even-value grandparent while the nodes
 * [6,x,8,x,x,x,x,x,x,x,x,x,x,x,x] are the even-value grandparents.
 * <p>
 * Constraints:
 * The number of nodes in the tree is between 1 and 10^4.
 * The value of nodes is between 1 and 100.
 */

/**
 * Definition for a binary tree node.
 *
 * `
 * public class TreeNode {
 *      int val;
 *      TreeNode left;
 *      TreeNode right;
 *      TreeNode(int x) { val = x; }
 * }
 * `
 */
class Solution {
    public int sumEvenGrandparent(TreeNode root) {
        // Stack for DFS
        Deque<TreeNode> treeStack = new LinkedList<>();
        int sum = 0;
        boolean isEven = false;
        treeStack.push(root);

        sum = getSum(root, isEven, sum, treeStack);

        return sum;
    }

    // Recursive DFS
    public int getSum(TreeNode root, boolean isChildrenToBeAdded, int sum, Deque<TreeNode> treeStack) {
        if (!treeStack.isEmpty()) {
            TreeNode currentNode = treeStack.pop();

            // Add current node's children o sum as current node's parent has even number
            if (isChildrenToBeAdded) {
                if (currentNode.left != null) {
                    sum += currentNode.left.val;
                }
                if (currentNode.right != null) {
                    sum += currentNode.right.val;
                }
            }

            // Check if current node has even number so that its grandchildren can be added to sum
            if (currentNode.val % 2 == 0) {
                isChildrenToBeAdded = true;
            } else {
                isChildrenToBeAdded = false;
            }

            // Traverse Left sub-tre
            if (currentNode.left != null) {
                treeStack.push(currentNode.left);
                sum = getSum(currentNode.left, isChildrenToBeAdded, sum, treeStack);
            }
            // Traverse Right sub-tre
            if (currentNode.right != null) {
                treeStack.push(currentNode.right);
                sum = getSum(currentNode.right, isChildrenToBeAdded, sum, treeStack);
            }
        }

        return sum;
    }
}
