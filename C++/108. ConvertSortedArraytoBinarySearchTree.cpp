/*
 *  
 *  Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 *  For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 *  Example:
 *
 *  Given the sorted array: [-10,-3,0,5,9],
 *
 *  One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *
 *       0
 *      / \
 *    -3   9
 *    /   /
 *  -10  5
 *
 */
 //-----------------------------------Solution------------------------------------
 /*
  * 
  * This is one of the standard problem of converting the given sorted array into Binary Search Tree (BST).
  * Inorder traversal of a BST always gives us an array in sorted order which means that root of the BST tree comes in the middle of the array.
  * Middle element of the array becomes the root of the BST. The elements to the left of the middle element (let's call LHS) contribute to the left sub-tree. 
  * And the elements to the right of the middle element (Let's call this RHS) contribute to the right sub-tree. 
  * We, then recursively find the root of the LHS and RHS till the build of the tree is complete.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        TreeNode* rootNode = createBST(0, nums.size()-1, nums);
        return rootNode;
    }
    
    TreeNode* createBST(int low, int high,  vector<int> &nums) {
        if (low>high)
            return NULL;
        int mid = (high + low) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createBST(low, mid-1, nums);
        root->right = createBST(mid+1, high, nums);
        return root;
    }
};
