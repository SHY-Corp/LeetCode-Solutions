/*SYMMETRIC TREE*/

/*PROBLEM STATEMENT*/
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*/

/*EXAMPLES*/
/*
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
*/
 
/*
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        TreeNode *root1 = root->left;
        TreeNode *root2 = root->right;
        return _isSymmetric(root1, root2);
    }
    
    bool _isSymmetric(TreeNode *root1, TreeNode *root2)
    {
        if(root1 == root2)
            return true;
        else
        {
            if(root1 == NULL || root2 == NULL)
                return false;
            else
            {
                if(root1->val == root2->val)
                    return _isSymmetric(root1->left, root2->right) &&
                            _isSymmetric(root1->right, root2->left);
                else
                    return false;
            }
        }
    }
    
};
