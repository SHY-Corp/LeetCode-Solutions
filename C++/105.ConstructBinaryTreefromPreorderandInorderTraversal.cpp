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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preOrdIdx, int start, int end, unordered_map<int, int>& m)
    {
        //edge case: if no elements, return NULL
        if(start>end)
            return NULL;

        //storing the preorder index element as root value and incrementing this element
        int val = preorder[preOrdIdx];
        preOrdIdx++;
        //assigning this value as the new root value
        TreeNode *root = new TreeNode(val);
        //storing the current value at index in the map in a variable, which is the root
        int inOrdIdx = m[val];

        //building left and right subtrees respectively
        root->left = helper(preorder, inorder, preOrdIdx, start, inOrdIdx-1, m);
        root->right = helper(preorder, inorder, preOrdIdx, inOrdIdx+1, end, m);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preOrdIdx = 0;

        //for storing the inorder vector's values to its index
        unordered_map<int, int> m;
        for(int i=0; i<n; i++)
        {
            m[inorder[i]] = i;
        }
        //calling a helper funtion for constructing a binary tree
        return helper(preorder, inorder, preOrdIdx, 0, n-1, m);
    }
};

//TC=O(n), n = no. of nodes (n nodes to add to the hash map)
//SC=O(n), for storing tree nodes in a hashmap
