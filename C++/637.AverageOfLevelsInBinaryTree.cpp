class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        /*In order to find the average at each level, I am creating a temporary queue
          'curr' which will store the children of a pointer(n) pointing to current node.
           It will also add those values as they join the queue and increase the node count
           after the first element has popped, till the queue is not empty. As soon as the
           queue is empty, I push this temporary queue into the original queue(Q) and 
           push the average of that level(curr queue) into a vector 'avg' which is 
           returned in the end! */
        queue<TreeNode*> Q;
        vector<double> avg;
        int count;
        double sum;
        
        Q.push(root);
        
        while(!Q.empty())
        {
            sum = 0.0;
            count = 0;
            queue<TreeNode*> curr;         //temporary queue for current level
            
            while(!Q.empty()){
            TreeNode *n = Q.front();       //n is the reference to the first node in this queue
            Q.pop();                      /*now we pop and keep a track of sum and nodes, so everytime 
                                            there is a temporary queue, we will have the sum of its nodes
                                            and the count of those nodes */
            sum=sum + n->val;
            count++;
            /* Here we are checking if the node we just popped has children. So
               if they do, we are adding those children to the temporary queue
            */
            if(n->left!=NULL)      
                curr.push(n->left);
            if(n->right!=NULL)
                curr.push(n->right);
        }
        /*Now that the queue is empty, I am pushing this temporary queue into Q and 
        calculating the average of values at each level */
        Q = curr;
        avg.push_back(sum/count);
        }     
        return avg;
    }
};