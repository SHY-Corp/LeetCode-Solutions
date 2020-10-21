/*Leetcode Problem #104- Maximum Depth of Binary tree*/

/*Finding the height/depth of a binary tree or simply calculating the number of generations/levels from the root node to the leaf nodes.*/

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
    int maxDepth(TreeNode* root) {

        if(root==NULL){
            return 0;
        }
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return max(l,r)+1;
    }
};
