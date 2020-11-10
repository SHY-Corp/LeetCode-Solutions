// problem - 563. Binary Tree Tilt

/*
    Given the root of a binary tree, return the sum of every tree node's tilt.

    The tilt of a tree node is the absolute difference between the sum of all left subtree node values 
    and all right subtree node values. If a node does not have a left child, 
    then the sum of the left subtree node values is treated as 0. The rule is similar if 
    there the node does not have a right child.
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
    // global variable to store the answer(tilt)
    int answer = 0;
public:
    // calculates the tilt recursively
    int calcTilt(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = calcTilt(root->left);
        int right = calcTilt(root->right);
        answer += abs(right - left);
        return left + right + root->val;
    }
    
    int findTilt(TreeNode* root) {
        calcTilt(root);
        return answer;
    }
};

// Time Complexity = O(n) Linear Time
// Space Complexity = O(n) Linear Time [O(depth of the tree)]