/*
Aim: We need to find the lowest common ancestor of the deepest(farthest from the root) leaves

Soln: Simple DFS 

      fun() function finds the depth of the deepest node and simultaneouly returns the node.
      
*/
class Solution {
public:
    int deepest = 0;    // intial depth
    TreeNode* lca;      // node to be returned
    
    int fun(TreeNode* root, int depth){
        
        deepest = max(depth, deepest);  // contains the curr max depth
        if(!root)
            return depth;
        
        int l = fun(root->left, depth+1);   // returns depth of left child
        int r = fun(root->right, depth+1);  // return depth of right child
        
        if(l == deepest && r == deepest)
            lca = root;     // if the node is the farthest from root
        
        return max(l ,r);   // return the deepest leaf node
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return nullptr;
        fun(root, 0);
        
        return lca;
    }
};

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
