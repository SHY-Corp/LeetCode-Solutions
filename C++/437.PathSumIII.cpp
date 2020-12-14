class Solution {
public:
    int count=0;
    
    int pathSum(TreeNode* root, int sum) { 
        vector<int> v;
        checkTarget(root,v, sum);
        return count;     
    }
 /* I am traversing the whole binary tree and storing its node values into 
    a vector 'v'. When we have all the values in our vector array, I start 
    adding values from the end of that vector to an integer named 'target'
    which is 0 initially. So if, the sum is equal to target, I increment the 
    count. This count is essentially the number of paths that add up to the 
    given sum. Once the condition is false, i.e. i<0, control shifts to the above 
    function which returns that count.
 */   
    void checkTarget(TreeNode* root,vector<int> v, int sum)
    {
        int i, n, target;
        target=0;
        
        if(root==NULL)
            return ;
        
        v.push_back(root->val);   //vector array storing the current root value.
        
        checkTarget(root->left,v, sum);
        checkTarget(root->right,v, sum);
        
        n = v.size();
        for(i=n-1; i>=0; i--)
        {
            target=target+v[i];
            if(sum==target)
                count++;
        }
       // v.pop_back();
    }
};