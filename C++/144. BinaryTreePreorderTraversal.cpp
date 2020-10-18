/*

Problem : Given the root of a binary tree, return the preorder traversal of its nodes' values.

Approach : Used recursion in order to traverse binary tree.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    
    void traverse(TreeNode* t){
        if(t==NULL ) return;
        v.push_back(t->val);
        traverse(t->left);
        traverse(t->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return v;
        
    }
};
