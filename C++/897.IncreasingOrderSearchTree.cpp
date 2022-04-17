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
/* // implementing a space optimized solution below. This solution has TC: O(n), SC: O(n), where n = number
   // of nodes and we use extra space(vector) for storing the the node values
class Solution {
    vector<int> v;
public:
    void inorder(TreeNode* &root, vector<int>& v)
    {
        if(root==NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root, v);
        TreeNode* temp = new TreeNode();
        TreeNode* curr = temp;

         for(int x: v)
         {
             curr->right = new TreeNode(x);
             curr = curr->right;
         }
        return temp->right;
    }
};
*/

class Solution {
    //creating a dummy node from which we will rearrange the tree in in-order
    TreeNode* dummy = new TreeNode();
public:
    void helper(TreeNode* root)
    {
        if(root==NULL)
            return;

        helper(root->left);
        //making left node NULL
        root->left = NULL;
        //the right child of dummy node will now be the left-most child of the current tree
        dummy->right = root;
        //updating dummy node with the current root after the 1st recursive call for further processing
        dummy = root;
        helper(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        //creating a reference to the dummy node so we don't lose it during the subsequent operations
        TreeNode* curr = dummy;
        //generating a right-skewed tree via this helper function
        helper(root);
        //Note: returning curr->right, instead of curr as the curr node holds dummy which isn't needed
        return curr->right;
    }
};

/*
   TC: O(n)
   SC: O(h), where h = height of the tree
*/
