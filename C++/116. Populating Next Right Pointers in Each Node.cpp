/*
Problem link:  https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.

Definition for a Node:
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

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/


/***************** Method1: Using Level Order Traversal*********************/
/*
The idea here is:
We will traverse the tree by level order traversal and at each level we will connect the
previously visited node to the current node

*/

class Solution {
public:
    Node* connect(Node* root)
    {
        if (root == NULL)
            return root;
        queue<Node*> que;
        que.push(root);

        while (!que.empty())
        {
            Node *prev = NULL;
            int n = que.size();
            for (int i = 0; i < n; i++)
            {
                Node *curr = que.front();
                que.pop();
                if (prev == NULL)
                {
                    prev = curr;
                }
                else
                {
                    prev->next = curr;
                    prev = curr;
                }
                if (curr->left)
                    que.push(curr->left);
                if (curr->right)
                    que.push(curr->right);

            }
        }
        return root;
    }
};

/****************** Method2: Using preorder traversal*********************/
/*
The idea here is:
(i) Since this approach is a top-down approach, it is safe to assume that when we are populating neighbours for
    child nodes of current node, current node's neighbours is already populated with next pointers.
    Using this assumption, it is now easy to populate neighbours for current node's child nodes.
(ii) While populating neighbours, we populate neighbours in the right subtree before populating the neighbours
     in the left subtree. This allows us to access all nodes at the level of current node using neighbour-node
     chain while populating neighbours for current node's child nodes.

Algorithm:
i) First we populate "neighbour for left child of current node".
    If current node's left child is not null then:
        If "right child of current node" is not null then we make "right child of current node" as the
           neighbour(i.e. next) of left child of current node.
        Else:(right child of current node is null)
            Now we need to find the first non-null node after the left child at left child's level and
            make that node as left child's neighbour.
ii) If right child of current node is not null:
    find the first non-null node after the right child at right child's level and
            make that node as right child's neighbour.

iii) call the function recursively on right child and then on left child.

*/
class Solution {
public:

    Node* connect(Node* root)
    {
        if (root == NULL)
            return root;

        if (root->left != NULL)
        {
            if (root->right != NULL)
                root->left->next = root->right;
            else
            {
                Node *parentNext = root->next;
                Node *neighbourNode;
                while (parentNext != NULL)
                {
                    neighbourNode = (parentNext->left != NULL) ? parentNext->left : parentNext->right;
                    if (neighbourNode != NULL)
                    {
                        root->left->next = neighbourNode;
                        break;
                    }
                    parentNext = parentNext->next;
                }
            }
        }

        if (root->right != NULL)
        {
            Node *parentNext = root->next;
            Node *neighbourNode;
            while (parentNext != NULL)
            {
                neighbourNode = (parentNext->left != NULL) ? parentNext->left : parentNext->right;
                if (neighbourNode != NULL)
                {
                    root->right->next = neighbourNode;
                    break;
                }
                parentNext = parentNext->next;
            }
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};