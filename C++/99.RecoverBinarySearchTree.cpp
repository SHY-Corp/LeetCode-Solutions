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
private:

    void markTree(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end) {
        if (!root)
            return;
        //recursive call to left subtree
        markTree(root->left, prev, first, end);
        //if there is a previous node in the tree, compare its value to root node
        if (prev)
        {
            //if root node value is less, check further
            if (root->val < prev->val)
            {
                //if there is no first node, assign to it the prev node
                if (!first)
                    first = prev;

                //and assign the end node with root node's value
                end = root;
            }
        }
        //assign the prev node as the root node
        prev = root;
        //and make a recursive call to the right subtree
        markTree(root->right, prev, first, end);
    }


public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *end = nullptr;
        //inorder recursive function to iterate over tree nodes and save them as prev, first and last nodes
        markTree(root, prev, first, end);

        //first and last nodes will have the values that need to be swapped
        swap(first->val, end->val);
        return;
    }
};

//TC: O(n), for traversing over n nodes
//SC: O(1), since we are using nodes for swapping, so not considering the stack space
