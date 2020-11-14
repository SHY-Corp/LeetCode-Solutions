// problem - 1026. Maximum Difference Between Node and Ancestor

/*
    Given the root of a binary tree, find the maximum value V for which there exist different 
    nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

    A node A is an ancestor of B if either: any child of A is equal to B, or any 
    child of A is an ancestor of B.
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
    // global variable to store the difference(answer)
    int diff = 0;
public:
    pair<int, int> calcDiff(TreeNode* root) {
        // base cases
        // returns maximum value for minima and minimum value for maxima
        if(root == nullptr) return make_pair(999999, -1); 
        // when both left and right is null then both minima and maxima is same(root's value)
        if(root->left == nullptr && root->right == nullptr) return make_pair(root->val, root->val); 
        
        // recursive cases
        pair<int, int> left = calcDiff(root->left);
        pair<int, int> right = calcDiff(root->right);
        
        // minima = minimum of left's minima and right's minima
        int minima = min(left.first, right.first);
        // maxima = maximum of left's maxima and right's maxima
        int maxima = max(left.second, right.second);
        
        // calculating diff
        int temp = max(abs(minima - root->val), abs(maxima - root->val));
        diff = max(diff, temp);
        
        // comparing minima and maxima with root's val
        minima = min(minima, root->val);
        maxima = max(maxima, root->val);
        
        return make_pair(minima, maxima);        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        calcDiff(root);
        return diff;
    }
};

// Time Complexity = O(n) Linear Time
// Space Complexity = O(n) Linear Time [O(depth of given tree)]