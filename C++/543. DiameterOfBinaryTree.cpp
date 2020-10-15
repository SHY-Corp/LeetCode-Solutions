//int diameterHelper(TreeNode * node) will traverse the whole tree and at each step look right
//and return the maximum width possible from the point where it is standing to the rights. Then
//looks left and do the same thing. The width then is the sum. This is repeated form each point
// (node) in the tree. Finally  vector<int> result is filled with widths from all possible points.
// diameterOfBinaryTree(TreeNode* root) returns the maximum element in vector<int> result as the result 
//or 0 if it's empty



#include <bits/stdc++.h>
using namespace std;

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
    vector<int> results;
    
    bool is_leaf(TreeNode * node){
        return  node->left == nullptr && node->right == nullptr ;
    }
    
    int diameterHelper(TreeNode * node){
        int right=0, left=0;
        if(node == nullptr) return 0;
        else{
            if (node->right) right = diameterHelper(node->right) + 1;
            if (node->left) left = diameterHelper(node->left) + 1;
            results.push_back(right+left);
        }
        return max(right, left);    
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameterHelper(root);
        return results.empty() ? 0 : * max_element(results.begin(), results.end());
    }
};
