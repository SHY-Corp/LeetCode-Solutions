/*
Problem: https://leetcode.com/problems/range-sum-of-bst/
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
The binary search tree is guaranteed to have unique values.

*/
class Solution
{
public:
    int sum = 0;

    int rangeSumBST(TreeNode *root, int L, int R)
    {
        postOrderTraversal(root, L, R);
        return sum;
    }

    void postOrderTraversal(TreeNode *root, int L, int R)
    {
        if (root == nullptr)
            return;

        postOrderTraversal(root->left, L, R);
        postOrderTraversal(root->right, L, R);

        if (root->val >= L && root->val <= R)
            sum += root->val;
    }
};
