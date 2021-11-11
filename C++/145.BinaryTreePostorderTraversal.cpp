/* Algorithm Postorder(tree)
 *  1. Traverse the left subtree, i.e., call postorderTraversal(left-subtree)
 *  2. Traverse the right subtree, i.e., call postorderTraversal(right-subtree)
 *  3. Visit the root.
 *
 *   While visiting the root, I'm pushing the value at that node and returning the final vector as output.
 */

class Solution {
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        //base condition
        if(root==NULL)
            return v;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        v.push_back(root->val);

        return v;
    }
};
