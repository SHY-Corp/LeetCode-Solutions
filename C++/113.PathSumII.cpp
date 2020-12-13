/* I have used recursion with DFS. Notice the return datatype. We are supposed to 
   find all the possible routes for a given target(sum). So, I take the classic
   base condition(if root is NULL). Then I call a function thus passing the root, 
   sum and vector as parameters.
*/
class Solution {
public:
    vector<vector<int>> path;
    //void checkPath(TreeNode* root, int sum, vector<int> v);
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return {};
        vector<int> v;
        checkPath(root, sum, v);
        return path;
    }
    
    void checkPath(TreeNode* root, int sum, vector<int> v)
    {
        /* In the function definition, I have traversed the tree through
           DFS(preorder). The vector 'v' I  defined in the pathSum() function will
           be holding the current root value thereby checking its left and right conditions.
           So, if we have reached the leaf node and our sum is matching the root value, we
           push this into another vector 'path'. However, if there are more children in the
           left and right leaves respectively, we are recursively calling the checkPath function
           thereby passing the parameters. Once, the whole function is executed, the control shifts
           to the main function and we get our final routes!
        */
        v.push_back(root->val);   //v holding current root value
        
        if(root->left==NULL && root->right==NULL && sum==root->val)
               path.push_back(v);
        if(root->left!=NULL)
            checkPath(root->left, sum-root->val, v);
        if(root->right!=NULL)
            checkPath(root->right, sum-root->val, v);
        //v.pop_back();         
    }
};

/* NOTE: In the recursive function call, we are passing 'sum-root->val' as the parameter. Reason  being,
   if we reach NULL while tree traversal, and the sum doesn't match our target, then we backtrack, which
   also implies that we need to subtract the value of leaf node we added previously to check!
*/