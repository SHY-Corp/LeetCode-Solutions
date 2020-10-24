/*
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
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
	// this function traverses the tree in preorder traversal while creating the string ans
	// first we add an opening bracket
	// add the value of current node is it's not null
	// recursively solve the problem for left child
	// if left child is null and right child is not null add opening and closing brackets
	// recursively solve the problem for right child
    void treeUtil(TreeNode *root, string &ans){
        if(root){
            ans += "(";
            ans += to_string(root->val);
            treeUtil(root->left, ans);
            if(root->left == NULL && root->right != NULL)
                ans += "()";
            treeUtil(root->right, ans);
            ans += ")";
        }
    }
    
    string tree2str(TreeNode* t) {
        if(t == NULL)
            return "";
        string ans = "";
        treeUtil(t, ans);
		// treeUtil generates a string where we have opening and closing brackets surrounding the root
        return ans.substr(1, ans.length()-2);
    }
};