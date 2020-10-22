#include <iostream>
using namespace std;
 
class node
{
	public:
	int data;
	node* left;
	node* right;
	
};
node* merge(node  *t1,node*t2)
{
	if(!t1)
	return t2;
	if(!t2)
	return t1;
	t1->data+=t2->data;
	t1->left = merge(t1->left,t2->left);
	t1->right = merge(t1->right,t2->right);
	return t1;
}
