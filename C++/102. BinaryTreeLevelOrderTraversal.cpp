/*
In this problem, we need to find out the level order traversal of the given binary tree.

These are the steps which we will follow :

1)Create a vector of vectors which will store the integers of each level in order.

2)If the root is NULL then we can directly return.

3)Else, we will create a deque to hold the objects of the type TreeNode and push the root node's address into it.

4)Now, we need to do this(step 5), until the deque is empty.

5)Find out the length of the existing deque(this is len), create a vector of integers(current_level) to hold these numbers which are the 
  elements of that particular level. Now run a loop of the size len, and keep on popping out elements from the front and append it to the
  current_level vector and simultaneously we'll keep on pushing the address of the left and right child nodes of the current node if there
  exists any.



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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if (!root) return result;
        
        deque<TreeNode*> queue;
        queue.emplace_back(root);
        
        while (!queue.empty()) {
            int len = queue.size();
            vector<int> current_level;
            
            while (len-- > 0) {
                auto node = queue.front();
                queue.pop_front();
                
                current_level.emplace_back(node->val);
                
                if (node->left)
                    queue.emplace_back(node->left);
                
                if (node->right)
                    queue.emplace_back(node->right);
            }
            result.emplace_back(current_level);
        }
        
        return result;
    }
};