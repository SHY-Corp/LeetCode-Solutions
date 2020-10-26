/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // Return the other tree, if either of the tree is null.
        if(!t1)
            return t2;
        if(!t2)
            return t1;

        /* Create a new node, with value as the summation of both the nodes. Attach the left and right
        children and recur for them. */
        TreeNode* t = new TreeNode(t1->val + t2->val);
        t->left = mergeTrees(t1->left, t2->left);
        t->right = mergeTrees(t1->right, t2->right);
        return t;
    }
};
