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
    queue<TreeNode*> q;
    TreeNode* searchBST(TreeNode* root, int val) {

        //return NULL if the value is not found
        if(root==NULL)
            return NULL;

        if(val == root->val)
            return root;

        //if the value is less than the root value, search in LEFT sub-tree and return that sub-tree
        if(val<root->val)
            return searchBST(root->left, val);

        //else, search in the RIGHT sub-tree and return that sub-tree
        else
            return searchBST(root->right, val);

        /* //iterative solution has SC=O(1)
        while(root)
        {
            if(root->val == val) return root;
            if(root->val >= val) root=root->left;
            else root=root->right;
        }
        return NULL;
        */
    }
};

/*
    TC: O(logn)
    SC: O(n), where n = recursive calls
*/
