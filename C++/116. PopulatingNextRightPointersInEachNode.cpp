/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // Base terminating condition. Applicable for children of leaf nodes.
        if(!root) {
            return NULL;
        }
        // Connect the left child to the right child.
        if(root->left) {
            root->left->next = root->right;
        }
        // Connect the right child to left child of right sibling, if applicable.
        if(root->right) {
            root->right->next = root->next ? root->next->left : NULL;
        }
        // Recur for the children.
        root->left = connect(root->left);
        root->right = connect(root->right);
        return root;
    }
};
