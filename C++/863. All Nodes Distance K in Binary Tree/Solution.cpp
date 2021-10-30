class Solution {
public:
    vector<int> res;
    void printAtK(TreeNode* root,int k){
        if(root==NULL)
            return;
        if(k==0){
            res.push_back(root->val);
            return;
        }
        printAtK(root->left,k-1);
        printAtK(root->right, k-1);
        return;
    }
    
    int helper(TreeNode* root, TreeNode* target, int k){
        if(root==NULL)
            return -1;
        
        if(root==target){
            printAtK(root,k);
            return 0;
        }
        
        int DL=helper(root->left,target,k) ;
        if(DL!=-1){               // if target is in the left subtree
            if(DL+1==k){  
                res.push_back(root->val);
            }
            else{
                printAtK(root->right,k-DL-2);
                
            }
            return DL+1;
        }
        
        int DR=helper(root->right,target, k);
        if(DR!=-1){           //  if target is in the right subtree
            if(DR+1==k){
                res.push_back(root->val);
            }
            else {
                printAtK(root->left,k-DR-2);
            }
            return DR+1;
        }
        return -1;
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        helper(root, target, k);
        return res;
    }
};
