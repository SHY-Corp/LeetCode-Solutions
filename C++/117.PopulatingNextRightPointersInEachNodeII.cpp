/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root!=NULL)
            q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            //creating a temporary node pointing to NULL
            Node* temp = NULL;

            //iterative over the queue
            for(int i=0; i<n; i++)
            {
                Node* curr = q.front();
                q.pop();

                //when i==0 it means we are at left most node of the level
                //so we assign temp = cur
                if(i==0)
                    temp = curr;

                //but for i>=1 we assign current as temp node's next and move temp node to current
                else
                {
                    temp->next = curr;
                    temp = temp-> next;
                }

                //pushing the left and right child of the curr node into the queue
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
      return root;
    }
};
