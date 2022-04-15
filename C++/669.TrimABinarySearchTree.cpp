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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL)
            return root;

        //if the current root value does exist between low and high, we have that value as a result and then
        //we check for its L and R children
        if(root->val>=low && root->val<=high)
        {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }

        //handling the case where it is a possibility that while a right child of the root MAY NOT lie in the
        //[low, high] range, the subsequent children of that right node MIGHT DO! And the same logic applies
        //to the left child of the root node
        if(root->val < low)
            return trimBST(root->right, low, high);
        return trimBST(root->left, low, high);

    }
};

/*
    TC: O(n), n = no. of nodes
    SC: O(n), because we will make recursive call to all the nodes
*/
