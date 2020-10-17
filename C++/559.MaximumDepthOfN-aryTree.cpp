/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*EXPLANATION :- We will be using here simple DFS the only difference being that there is no visited array as we have in case of graphs normally. The height() func takes two parameters root of the N-ary tree and initial height which is passed as 0 and the height increases as we mive further down the tree for every leaf node we calculate the max. depth so far for all the leaves*/

class Solution {
public:
    
    int ans=0;
    void height(Node*root,int ht)
    {
        if(root)
        {
            ht++;
            for(int i=0; i<root->children.size(); i++)
            {
                height(root->children[i],ht);
            }
            
            ans=max(ans,ht);
            
        }
    }
    
    int maxDepth(Node* root) 
    {
        if(root)
        {
            height(root,0);
            return ans;
        }
        return 0;
    }
};