class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        root.val = 0;
        queue.add(root);
        int maxLength = 0;
        while (!queue.isEmpty()) {
            Queue<TreeNode> newLevel = new LinkedList<>();
            int firstElement = queue.peek().val;
            int lastElement = firstElement;
            while(!queue.isEmpty()) {
                TreeNode current = queue.remove();
                if (current.left != null) {
                    current.left.val = current.val * 2;
                    newLevel.add(current.left);
                }
                if (current.right != null) {
                    current.right.val = current.val * 2 + 1;
                    newLevel.add(current.right);
                }
                if (queue.isEmpty()) {
                    lastElement = current.val;
                }
            }
            if (lastElement - firstElement + 1 > maxLength) {
                maxLength = lastElement - firstElement + 1;
            }
            queue = newLevel;
        }
        return maxLength;
    }
}
