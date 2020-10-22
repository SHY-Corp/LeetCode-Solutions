#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

void print_zigzag(Node* root){
    if (!root)
        return;
    
    stack <Node*> current, nextlevel;
    current.push(root);
    bool option = true;
    while (!current.empty()){
        Node* temp = current.top();
        current.pop();

        if (temp){
            cout<<temp->data<<" ";
        if (option) { 
            if (temp->left) 
                nextlevel.push(temp->left); 
            if (temp->right) 
                nextlevel.push(temp->right); 
            }
        else { 
            if (temp->right) 
                nextlevel.push(temp->right); 
            if (temp->left) 
                nextlevel.push(temp->left); 
            }  
        }
    }
}
int main()
{

    // making of a sample tree
    Node* root = new Node(10);  
    root->left = new Node(12);  
    root->right = new Node(13);  
    root->right->left = new Node(14);  
    root->right->right = new Node(15);  
    root->right->left->left = new Node(21);  
    root->right->left->right = new Node(22);  
    root->right->right->left = new Node(23);  
    root->right->right->right = new Node(24); 

    print_zigzag (root);
    
    return 0;
}

