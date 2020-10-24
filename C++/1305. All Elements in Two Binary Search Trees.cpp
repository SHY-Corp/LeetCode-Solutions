/*
    Given two binary search trees root1 and root2.

    Return a list containing all the integers from both trees sorted in ascending order.

    Example 1:
        Input: root1 = [2,1,4], root2 = [1,0,3]
        Output: [0,1,1,2,3,4]
    
    Example 2:
        Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
        Output: [-10,0,0,1,2,5,7,10]
*/

/**
  * Definition for a binary tree node.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* deleteMin(TreeNode* root,int &Min){
        if(root==NULL) return root;

        TreeNode* temp=root, *prev=NULL;
        while(temp->left != NULL) {
            prev=temp;
            temp=temp->left;
        }
        Min=temp->val;
        if(temp == root) root=root->right;
        else{
            prev->left=temp->right;
        }
        //delete temp;
        return root;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        int Min1, Min2;
        root1=deleteMin(root1, Min1);
        root2=deleteMin(root2, Min2);
        bool flag1=false, flag2=false;
        while(root1!=NULL || root2!=NULL){
            if(flag1 && Min1<Min2){
                ans.push_back(Min1);
                flag1=false;
            }
            else if(flag2 && Min1>Min2){
                ans.push_back(Min2);
                flag2=false;
            }
            else if(root1!=NULL && (root2==NULL || Min1<Min2)) {
                ans.push_back(Min1);
                root1=deleteMin(root1, Min1);
                if(root1==NULL) flag1=true;
            }
            else {
                ans.push_back(Min2);
                root2=deleteMin(root2, Min2);
                if(root2==NULL) flag2=true;
            }
        }
        if(flag1 && flag2 && Min1>Min2){
            ans.push_back(Min2);
            flag2=false;
        }
        if(flag1){
            ans.push_back(Min1);
        }
        if(flag2){
            ans.push_back(Min2);
        }
        return ans;
    }
};