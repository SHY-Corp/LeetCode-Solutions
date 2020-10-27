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
    TreeNode * solve(TreeNode * child, TreeNode * parent, TreeNode * root) {
        if(child->left==NULL && child->right == NULL) {
            root->val = child->val;
            return NULL;
        }
        if(child->left){
            child->left = solve(child->left, child, root);
        }
        else {
            root->val = child->val;
            return child->right;
        }
        return child;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val == key){
            if(root->left && root->right){
                root->right = solve(root->right, root, root);
            }
            else if(root->left){
                return root->left;
            }
            
            else if(root->right){
                return root->right;
            }
            else{
                return NULL;
            }
        }
        
        if(root->val<key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            root->left = deleteNode(root->left, key);
        }
        return root; 
    }
};