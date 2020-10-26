/*
Problem: https://leetcode.com/problems/range-sum-of-bst/
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
The binary search tree is guaranteed to have unique values.

*/
class Solution
{
public:
    // Create a variable sum which will store the result
    int sum = 0;

    int rangeSumBST(TreeNode *root, int L, int R)
    {
        // postorder traversal will compute the sum
        postOrderTraversal(root, L, R);
        return sum;
    }

    void postOrderTraversal(TreeNode *root, int L, int R)
    {
        if (root == nullptr)
            return;

        // compute left subtree's value
        postOrderTraversal(root->left, L, R);

        // compute right subtree's value
        postOrderTraversal(root->right, L, R);
        
        // if L <= node's value <= R then only add it to sum
        // otherwise do nothing
        if (root->val >= L && root->val <= R)
            sum += root->val;
    }
};
