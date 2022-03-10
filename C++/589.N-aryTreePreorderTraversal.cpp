class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        stack<Node*> s;

        if(root==NULL)
            return result;

        //pushing the root node into stack
        s.push(root);

        //updating the stack and pushing the values in result till the stack is not empty
        while(!s.empty())
        {
            //creating a temporary node pointing to the top of stack
            Node* temp = s.top();

            //pushing the value of temp node into the result vector
            result.push_back(temp->val);

            //popping the current value in the stack which was pushed into the result vector
            s.pop();

            //iterating in reverse to push the children of temp node into the stack
            for(int i=temp->children.size()-1; i>=0; i--)
            {
                s.push(temp->children[i]);
            }
        }
        return result;
    }
};
