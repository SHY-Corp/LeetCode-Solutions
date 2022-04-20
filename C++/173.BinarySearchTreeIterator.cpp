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
/*
class BSTIterator {
public:
    vector<int> v;
    int index = 0;

    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }

    int next() {
        //index++;    //this was giving a wrong output
       return v[index++];
    }

    bool hasNext() {
        if(index<v.size())
            return true;
        else
            return false;
    }
};

//TC = SC = O(n)

*/

class BSTIterator {
public:
    stack<TreeNode*> s;

    //implementing a partial inorder traversal and pushing the left child node in the stack
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        s.push(root);
        while(root->left)
        {
            s.push(root->left);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }

    int next() {
        //creating a temporary node that stores the current top node of stack
        TreeNode* temp = s.top();
        s.pop();
        //if temp node has a right child, calling inorder function on the right child of the temp node
        if(temp->right)
            inorder(temp->right);

        //temp->val will be the pointer to the right
        return temp->val;
    }

    bool hasNext() {
        //since this stack is storing nodes with their left child and popping them when required, it will
        //not contain nodes beyond a subtree, so if it's not empty, it means their is still a right child
        return !s.empty();
    }
};

/*
    TC: O(n)
    SC: O(h), h = height of the tree
*/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
