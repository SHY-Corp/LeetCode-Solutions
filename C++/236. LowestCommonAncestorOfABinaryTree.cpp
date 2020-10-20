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
    vector<TreeNode*> path;
    bool findPath(TreeNode* root, int k)
    {
        if(root == NULL) 
            return false;
        path.push_back(root);
        if(root->val == k)
            return true;
        if(findPath(root->left, k) || findPath(root->right, k))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /* The simplest working solution, in which we get the path from root to node
        for each of the nodes, compare the paths and print the solution. */
        int i;
        path.clear(); 
        findPath(root, p->val);
        vector<TreeNode*> a = path;
        path.clear(); 
        findPath(root, q->val);
        vector<TreeNode*> b = path;
        for(i = 0;i < a.size() && i < b.size(); i++)
            if(a[i]->val != b[i]->val)
                break;
        return a[i-1];
    }
};
