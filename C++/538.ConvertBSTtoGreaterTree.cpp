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
    //maintaining a sum variable
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
    //in-order traversal, but starting from right instead of left and updating the sum value with each call
        if(root)
        {
            //recursively calling the right subtree
            convertBST(root->right);
            //updating the sum variable with the root value
            sum += root->val;
            //updating the root value with that sum
            root->val = sum;
            //recursively calling the left subtree
            convertBST(root->left);
        }
        //return the root value, which will have the updated values
        return root;
    }
};

//TC: O(n), because we are doing a recursive call on each node(n)
//SC: O(n), for recursive calls on each node
