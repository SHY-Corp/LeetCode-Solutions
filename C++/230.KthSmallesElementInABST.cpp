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
    /*
    This function will follow inorder traversal:
    1. I will make a left call and check if it returned a non-zero value.
    2. If there is a non-zero value, I have found my kth smallest element so further processing is not
       needed and I will return whatever value I got from left subtree.
    2. Else, I will decrement the value of k and check if it's 0.
    3. If k is 0, I will return the current node's value as this element is our kth smallest value.
    4. Otherwise, I will make a right call and return that value, because, if the element is not found in
       our right subtree, then it will either return 0, or the kth element.
    5. The above steps will keep happening recursively till my k becomes 0 and I receive the value
       at that node which will be my kth smallest element.

    */
    int inorder(TreeNode* root, int &k)   //passing k by reference so the changes are reflected.
    {
        if(!root)
            return 0;
        int left = inorder(root->left, k);
        if(left)
            return left;
        k--;                   //decrementing k indicates the number of nodes being processed
        if(k==0)               //if this was 0-indexed, I would have checked for (k-1)
            return root->val;
        int right = inorder(root->right, k);
        return right;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        //using a helper function to traverse the whole tree using inorder traversal and
        //return the kth smallest value
        return inorder(root, k);
    }
};
