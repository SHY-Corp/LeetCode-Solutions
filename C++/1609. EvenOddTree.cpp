/*
    Problem Statement:
    A binary tree is named Even-Odd if it meets the following conditions:

    The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
    For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
    For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
    Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

    Problem Link:
    https://leetcode.com/problems/even-odd-tree/

    Approach:
    Breadth First Search Traversal
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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        vector<vector<int>> vals;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node && q.empty()){
                vals.push_back(temp);
                break;
            }
            if(!node){
                q.push(NULL);
                vals.push_back(temp);
                temp.clear();
                continue;
            }
            temp.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        int level = 1;
        for(auto nodes: vals){
            for(auto j: nodes) cout<<j<<" ";
            cout<<endl;
        }
        for(auto nodes: vals){
            int size = nodes.size();
            for(int i = 0;i<size;i++){
                if(i==0){
                    if(nodes[i]%2!=level%2) return false;
                    continue;
                }
                if(nodes[i]%2!=level%2) return false;
                if(level%2){
                    if(nodes[i]<=nodes[i-1]) return false;
                }else{
                    if(nodes[i]>=nodes[i-1]) return false;
                }
            }
            level++;
        }
        return true;
    }
    
};