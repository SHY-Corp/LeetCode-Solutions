/**
Problem:
This program gives the smallest number of numbers than the current number in the given array. 

Approach:
To solve the problem  simple Binary Search Tree with 2 extra fields is used: 
1) to hold the elements on the left side of a node.
2) to store the frequency of element. 

In this approach, we traverse the input array from the ending to the begging and add the elements into the BST. 
While inserting the elements to the BST, we can compute the number of elements which are lesser elements simply by computing the sum of frequency of the element and the number of elements to the left side of current node, 
if we are moving to right side of the current node.
**/
#include <bits/stdc++.h>
using namespace std;

// BST node structure
class Node
{

public:
    int val;
    int count;
    Node *left;
    Node *right;

    // Constructor
    Node(int num1, int num2)
    {
        this->val = num1;
        this->count = num2;
        this->left = this->right = NULL;
    }
};

// Function to addNode and find the smaller

int addNode(Node *&root, int value,
            int countSmaller)
{

    // Base case
    if (root == NULL)
    {
        root = new Node(value, 0);
        return countSmaller;
    }
    if (root->val < value)
    {
        return root->count +
               addNode(root->right,
                       value,
                       countSmaller + 1);
    }
    else
    {
        root->count++;
        return addNode(root->left, value,
                       countSmaller);
    }
}

// Driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int data[] = {10, 6, 15, 20, 30, 5, 7};
    int size = sizeof(data) / sizeof(data[0]);
    int ans[size] = {0};

    Node *root = NULL;

    for (int i = size - 1; i >= 0; i--)
    {
        ans[i] = addNode(root, data[i], 0);
    }

    for (int i = 0; i < size; i++)
        cout << ans[i] << " ";

    return 0;
}

