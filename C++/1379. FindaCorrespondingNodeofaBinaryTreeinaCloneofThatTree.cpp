/*
Given two binary trees original and cloned and given a reference to a node target in the original tree.
The cloned tree is a copy of the original tree.
Return a reference to the same node in the cloned tree.
Note that you are not allowed to change any of the two trees or the target node and the answer must be a 
reference to a node in the cloned tree.

Follow up: Solve the problem if repeated values on the tree are allowed.

Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node 
is a green node from the original tree. The answer is the yellow node from the cloned tree.
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
    vector<string> getTargetPath(TreeNode* root, TreeNode* target) {
        if(root == NULL) {
            vector<string> ret(0);
            return ret;
        }
    
        if(root == target) {
            vector<string> ret;
            ret.push_back("X");
            return ret;
        }
            
        
        vector<string> left = getTargetPath(root->left, target);
        if(left.size() != 0) {
            left.push_back("L");
            return left;
        }
           
        
        vector<string> right = getTargetPath(root->right, target);
        if(right.size() != 0) {
            right.push_back("R");
            return right;
        }
        
        vector<string> ret(0);
        return ret;
    }
    TreeNode* getTargetCopyUtil(TreeNode* root, TreeNode* target, vector<string> path) {
        string p = path[path.size() - 1];
        path.pop_back();
        
        TreeNode* ret;
        if(p == "X")
            return root;
        else if(p == "L")
            ret = getTargetCopyUtil(root->left, target, path);
        else
            ret = getTargetCopyUtil(root->right, target, path);
        
        return ret;
            
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<string> path;
        path = getTargetPath(original, target);
        return getTargetCopyUtil(cloned, target, path);
    }
};