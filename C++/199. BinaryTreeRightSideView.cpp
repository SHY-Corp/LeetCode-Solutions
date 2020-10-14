// Problem - 199. Binary Tree Right Side View

/*
    First we need to know what is the depth of the tree.
    Once we know the depth of the tree, we can initialize a vector of that size.
    Then we recursively add the rightmost element in every tree to that vector.
    Note that it will always change the value in every iteration, but it does not matter 
        since the last one (rightmost one) will be assigned on top of it all.
    Finally return the vector which contains the right side view of the binary tree.
*/

class Solution {
   public:
    void checkRight(vector<int> &right, TreeNode *currNode, int curr) {
        if (currNode == NULL) {
            return;
        }
        right[curr] = currNode->val;
        checkRight(right, currNode->left, curr + 1);
        checkRight(right, currNode->right, curr + 1);
    }

    int treeSize(TreeNode *node) {
        if (node == NULL) {
            return 0;
        } else {
            /* compute the depth of each subtree */
            int lDepth = treeSize(node->left);
            int rDepth = treeSize(node->right);

            if (lDepth > rDepth) {
                return (lDepth + 1);
            } else {
                return (rDepth + 1);
            }
        }
    }

    vector<int> rightSideView(TreeNode *root) {
        int n = treeSize(root);
        vector<int> right(n, 0);
        if (root == NULL) {
            return right;
        }
        right[0] = root->val;
        checkRight(right, root->left, 1);
        checkRight(right, root->right, 1);
        return right;
    }
};