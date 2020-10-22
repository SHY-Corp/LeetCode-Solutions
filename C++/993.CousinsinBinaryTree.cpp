
/* Problem 993 - Cousins in Binary Tree
https://leetcode.com/problems/cousins-in-binary-tree/
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.
*/
class Solution {
public:

    bool isCousins(TreeNode* root, int x, int y) {
        int num = x + y; /*using this as auxiliar var, to know if both x and y were found.
                         It can be done with two booleans also though*/

        queue<TreeNode*> q; /*queue to store each level of the tree = make the BFS*/

        int level_size = 0; /*To store how many nodes we have at each level, so we know when we
                            started to see a knew one and when it is finished*/

        map<int, int> parent; /*hash to have fast access of the parent of a specific node
                             map<key,value> where key is the node val and value is the parent val*/

        if (root != NULL) { /*Checking if root exists*/
            q.push(root); /*If so, the root is itself a level*/
        }
        else {
            return false;
        }

        /* Loop till we see all the nodes/levels of the tree */
        while (!q.empty()) {

            level_size = q.size(); /* How many nodes we have at this level */

            while (level_size--) { /* while we are looking for the nodes in the same level */

                TreeNode* top = q.front(); /* Pick a node*/

                if (top->val == x or top->val == y) { /* If this node is x or y */
                    num -= top->val; /* now we know that we jave to find the other one */
                }

                if (num == 0) { /*If num is 0, it means that we have already subtracted both x and y*/
                    if (parent[x] != parent[y]) { /*If parents are differents, they're counsins */
                        return true;
                    }
                    else {
                        return false;
                    }
                }

                q.pop(); /*we just saw the node, so we don't need this in the queue anymore*/

                /*If each right and left child of this node that we just saw exist, so we pick their  information. As storing their parent in the hash and push them on the queue */
                if (top->left) {
                    parent[top->left->val] = top->val;
                    q.push(top->left);
                }
                if (top->right) {
                    parent[top->right->val] = top->val;
                    q.push(top->right);
                }
            }
            /* As we just saw a entire level, if we saw a number but didn't see the other one, "num" will not  be the original x + y, nor 0  */
            if (num != (x + y)) {
                return false;
            }
        }
        return false; /*We traversed the entire tree and didn't found both x and y in the same level*/
    }
};