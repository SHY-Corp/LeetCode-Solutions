 /*
 * Testcase Example:  '"1-2--3--4-5--6--7"'
 *
 * We run a preorder depth first search on the root of a binary tree.
 * 
 * At each node in this traversal, we output D dashes (where D is the depth of
 * this node), then we output the value of this node.  (If the depth of a node
 * is D, the depth of its immediate child is D+1.  The depth of the root node
 * is 0.)
 * 
 * If a node has only one child, that child is guaranteed to be the left
 * child.
 * 
 * Given the output S of this traversal, recover the tree and return its
 * root.
 * 
 * Example 1:
 * Input: "1-2--3--4-5--6--7"
 * Output: [1,2,5,3,4,6,7]
 * 
 * Example 2:
 * Input: "1-2--3---4-5--6---7"
 * Output: [1,2,5,3,null,6,null,4,null,7]
 *  
 * Example 3:
 * Input: "1-401--349---90--88"
 * Output: [1,401,null,349,88,90]
 * 
 * Note:
 * The number of nodes in the original tree is between 1 and 1000. 
 * Each node will have a value between 1 and 10^9.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        TreeNode* root = nullptr;
        dfs(0, S, &root);
        return root;
    }

private:
    void dfs(int depth, string& S, TreeNode** root_ptr) {
        if (S.empty() || root_ptr == nullptr) {
            return;
        }

        int pos = 0;
        while (S[pos] == '-') {
            ++pos;
        }

        if (pos != depth) {
            return;
        }

        int val = 0;
        while (isdigit(S[pos])) {
            val = val * 10 + S[pos] - '0';
            ++pos;
        }

        S = S.substr(pos);
        *root_ptr = new TreeNode(val);

        dfs(depth + 1, S, &((*root_ptr)->left));
        dfs(depth + 1, S, &((*root_ptr)->right));
    }
};
