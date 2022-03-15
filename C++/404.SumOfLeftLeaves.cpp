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
    int sum = 0;

    //helper function for traversing over the tree nodes
    void helper(TreeNode* root, bool leftNode)
    {
        //check if there is a leftnode and the left as well as the right nodes are leaf nodes
        if(leftNode && root->left==NULL && root->right==NULL)
        {
            //if it's a leaf left node, add it to the sum variable and return
            sum = sum + root->val;
            return;
        }
        //recursive call to left node till we don't reach the left leaf node
        if(root->left!=NULL)
            helper(root->left, true);

        //recursive call to right node till we don't reach the right leaf node
        if(root->right!=NULL)
            helper(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;

        helper(root, false);
        return sum;
    }
};
