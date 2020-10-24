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
    // making two stacks to print the cirrent one and store the childs of the current node acc to direction
    stack <Node*> current, nextlevel;
    current.push(root);
    
    bool direction = true;

    while (!current.empty()){
        Node* temp = current.top();
        current.pop();

        if (temp){
            cout<<temp->data<<" ";
        // for print in left to right, and stck is lifo so, first left then right
        if (direction) { 
            if (temp->left) 
                nextlevel.push(temp->left); 
            if (temp->right) 
                nextlevel.push(temp->right); 
            }
        // else for right to left, therefore first right then left    
        else { 
            if (temp->right) 
                nextlevel.push(temp->right); 
            if (temp->left) 
                nextlevel.push(temp->left); 
            }  
        }
        // after every iteration changing the direction and swapping the current stack with the temmp sotred elements
        if (current.empty()) { 
            direction = !direction; 
            swap(current, nextlevel); 
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

