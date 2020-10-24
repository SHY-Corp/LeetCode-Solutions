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
 
/*  ---------------------------Problem Desciption--------------------------  */ 

/*
 *   Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 *   For example:
 *   Given binary tree [3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 *  return its bottom-up level order traversal as:
 *
 *  [
 *    [15,7],
 *    [9,20],
 *    [3]
 *  ]
 */
 
 /*  ---------------------------Solution--------------------------  */
 
 /* 
  * This is the classic example of level order traversal which we have implemented through queue.
  * We first check whether root is present or not, if root is not present.
  * In the queue, we first get the size of all the element present at that level.
  * We iterate through all the element of that element. By simultaneously storing the value in a 1D vector 
  * and insert its left and right node if present.
  * Once, all the element of a level is traversed. We insert the 1D vector into the 2D vector and then we iterate through the next level.
  * At the end, we reverse the 2D array and return the value
  */
 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> solution;
        
        if(!root)
            return solution;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int queueSize = q.size();
            vector<int> partSolution;
            for(int i=0; i<queueSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                partSolution.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            solution.push_back(partSolution);
        }
                     
        reverse(solution.begin(), solution.end());
        return solution;
    }
};
