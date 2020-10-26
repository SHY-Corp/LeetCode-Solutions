/*
Title: 1305. All Elements in Two Binary Search Trees

Problem: Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

Approach:
As given trees are BST's, the preorder traversal will give us sorted form of elements in the tree. So we do preorder traversal of each tree and store the order in a vector. Now we can merge these two vectors by just traversing them by two pointer algorithm. 

Time Complexity: O(n)
Space Complexity: O(n)

*/


class Solution {
public:
    
    void traverse(TreeNode* root, vector<int> &v){
        if(!root) return;
        traverse(root -> left, v);
        v.push_back(root -> val);
        traverse(root -> right, v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2,v;
        
        traverse(root1,v1);
        traverse(root2,v2);
        
        int i = 0,j = 0,p,q;
        p = v1.size();
        q = v2.size();
        
        while(i < p && j < q){
            if(v1[i]< v2[j]){
                v.push_back(v1[i++]);
            }else if(v1[i] == v2[j]){
                v.push_back(v1[i++]);
                v.push_back(v2[j++]);
            }else if(v1[i] > v2[j]){
                v.push_back(v2[j++]);
            }
        }
        while(i < p){
            v.push_back(v1[i++]);
        }
        while(j < q){
            v.push_back(v2[j++]);
        }
        
        return v;
        
    }
};
