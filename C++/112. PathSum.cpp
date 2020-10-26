/*
 *  Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 *
 *  Note: A leaf is a node with no children.
 *
 *  Example:
 *
 *  Given the below binary tree and sum = 22,
 *
 *       5
 *      / \
 *     4   8
 *    /   / \
 *   11  13  4
 *  /  \      \
 * 7    2      1
 *
 *  return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *
 */
 // ----------------------------------Solution---------------------------------
 /* 
  * 
  * This is one of the classis recursion problem where we have to traverse both the left and right path of a node recursively and  
  * passing the sum value in both the call by substracting the current value. And returning the 'or' of both the result. 
  * Here, the base conditions are if root is null, then we are not able to find the sum, hence it will  be false.
  * And, if root is present, both left and right node are null and root -> val is equal to sum, then we know that a path exist
  *
  */
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
    bool hasPathSum(TreeNode* root, int sum) {
        
        if (!root)
            return false;
        else if (root && !root->left && !root->right && root->val == sum)
            return true;
        else if (root && !root->left && !root->right && root->val != sum)
            return false;
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
