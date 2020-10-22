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
    TreeNode* constructMaximumBinaryTreeUtil(vector<int> vec, int l, int r)
    {
        if(l > r)
            return NULL;
        if(l == r)
            return new TreeNode(vec[l]);
        int max = vec[l];
        int index = l;
        for(int i = l; i <= r; i++) {
            if(max < vec[i]) {
                max = vec[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(vec[index]);
        root->left = constructMaximumBinaryTreeUtil(vec, l, index-1);
        root->right = constructMaximumBinaryTreeUtil(vec, index+1, r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTreeUtil(nums, 0, nums.size()-1);
    }
};
