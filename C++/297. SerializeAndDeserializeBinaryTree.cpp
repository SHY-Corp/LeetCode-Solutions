/*To serialize the tree,follow the preorder traversal algorithm and add the values using space as the distinguishing character and add "X" when the node is NULL*/

/*To deserialize the tree,follow the same preorder traversal,create the new nodes according to the value at the particular position of string and NULL node when value at that index is "X"*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string
    string serialize(TreeNode* root) {
       string s="";
        if(root==NULL)//Whenever root is NULL,then add "X ";
            return "X ";
        s+=(to_string(root->val)+" ");//Add value+space,serialize left,then right.
        s+=serialize(root->left);
        s+=serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* func(string data,int& ind)
    {
        if((data[ind]=='X')||(ind>=data.length()))//When value at index ind is 'X' that implies the node in the main tree is NULL
        {
            ind+=2;
            return NULL;
        }
        string sx="";
        while((ind<data.length())&&(data[ind]!=' '))//TO Get the value of the node
        {
            sx+=data[ind];
            ind++;
        }
        ind++;
        int temp1=stoi( sx );
        TreeNode* nx=new TreeNode(temp1);//Create the node,then iterate for left and right
        nx->left=func(data,ind);
        nx->right=func(data,ind);
        return nx;
    }
    
    TreeNode* deserialize(string data) {
        int ind=0;
        return func(data,ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
