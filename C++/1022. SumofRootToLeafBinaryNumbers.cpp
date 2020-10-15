// Problem:
// You are given the root of a binary tree where each node has a value 0 or 1.
// Each root - to - leaf path represents a binary number starting with the most significant bit.

// For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

// For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
// Return the sum of these numbers. The answer is guaranteed to fit in a 32 - bits integer.

// Approach:
// In the dfs, pass a variable (here, curr) in the parameter,
// which will store binary number from root to leaf. Thus, curr will be nothing but value
// of current value plus previous curr shifted once(or say multiplied by 2).
// Once we reach the leaf node, add it to a variable(here, sum) which will contain sum of
// all those binary values i.e. required answer.


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
	int sum;
	void dfs(TreeNode* root, int curr)
	{
		if (!root)
			return;
		curr = (curr << 1) + root->val;
		if (!root->left and !root->right)
		{
			sum += curr;
			return;
		}
		dfs(root->left, curr);
		dfs(root->right, curr);
	}
	int sumRootToLeaf(TreeNode* root) {
		int curr;
		sum = curr = 0;
		dfs(root, curr);
		return sum;
	}
};
