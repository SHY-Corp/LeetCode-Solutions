/* I have taken recursive approach here. I check if the root
   node is null or not. If it's not, I check for subsequent left
   and right nodes and their children. I have used the if-else ladder
   to check for all the cases. 
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)                //if root is null, the depth is 0
            return 0;
        else if(root->left==NULL)     //if left child is null, I return the depth using right child
            return minDepth(root->right)+1;
        else if(root->right==NULL)    //if right is null, I return the depth using left child.
            return minDepth(root->left)+1;
        else if(root->left!=NULL && root->right!=NULL)   //finally, if none of them are null, I will
            return min(minDepth(root->left), minDepth(root->right))+1;  //return the minimum depth of the 2
        else
            return 1;
    }
};

***************************************************************************************************************************

/* I am including the BFS approach too. Base case(root==NULL) is the same, however, I have a counter
   this time. I create a queue and push the root node into it. The idea is, I increase the count
   and then return that count value while traversing through that tree using queue, while the queue
   is not empty. Also, for traversing, we have another while loop which executes after decrementing
   the queue size.
*/
int minDepth(TreeNode* root) {
        if(!root)
            return 0;

        queue<TreeNode*> q;
        int counter = 0;
        q.push(root);

        while(!q.empty()){
            int n = q.size();

        /*So now, I am incrementing the counter and executing the while loop. I am initialising my
          root node as the reference to front node and then removing the front node through pop() funtion.
          After that I check for 3 conditions using multiple 'if' statements. The first statement returns 
          the count value if both left and right children are not equal to NULL. However, if they have
          children which are NOT EQUAL to NULL, I am pushing them into the queue. This loop runs till my
          queue is not empty.
        */    
            counter++;
            while(n--){
                root = q.front();
                q.pop();
                if(!root->left and !root->right)return counter;
                if(root->left)q.push(root->left);
                if(root->right)q.push(root->right);
            }
        }
        return 0;
    }
