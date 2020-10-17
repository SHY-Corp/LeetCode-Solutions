#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
struct node
{
	struct node *leftChild;
	int data;
	struct node *rightChild;
};
struct node *root=NULL;
//int const MAX=100;
int MAX=100;
struct node *sta[100];
int top=-1,leftheight=0,rightheight=0;
void push(struct node *ptr);
struct node *pop();
void preorder(struct node* ptr);
void display(struct node *ptr);
struct node *create();
void inorder(struct node* ptr);
bool c=true;
int co=0;
struct node *check(struct node *ptr,int count,int element)
    {
    	cout<<" count : "<<count<<"\n";
    	co=count;
        if(ptr==NULL)
            return NULL;
        if(ptr->data==element)
            return ptr;
        struct node* parent=ptr;
        struct node* ch=check(ptr->leftChild,count+1,element);
        if(ch!=NULL&&c==true)
        {
            c=false;
            return parent;          
        }
        if(c)
        {
            parent=ptr;
            ch=check(ptr->rightChild,count+1,element); 
            if(ch!=NULL&&c==true)
        	{
            c=false;
            return parent;          
        	}
        }
        
        return ch;
    }
    bool isCousins(struct node *ptr, int x, int y) 
    {
        int co1,co2;
        co=0;
        c=true;
        struct node *n=check(ptr,0,x);
        co1=co;
        co=0;
        c=true;
        struct node *m=check(ptr,0,y);
        co2=co;
        if(co1==co2&&n->data!=m->data)
            return true; 
        else return false;
    }
/*int heightofleftsubtree(struct node* ptr)
{
	if(ptr==NULL)
	return 0;
	while(ptr->leftChild!=NULL)
	{
	  ptr=ptr->leftChild;
	  leftheight++;	
	}
	if(ptr->rightChild==NULL)
	return leftheight;
	else heightofleftsubtree(ptr->rightChild);
}
int heightofrightsubtree(struct node* ptr)
{
	if(ptr==NULL)
	return 0;
	while(ptr->rightChild!=NULL)
	{
		ptr=ptr->rightChild;
	    rightheight++;
	}
	if(ptr->leftChild==NULL)
}*/
void push(struct node *ptr)
{
	if(top==(MAX-1))
	{
		printf("Stack OverFlow\n");
		return;
	}
	else sta[++top]=ptr;
}

struct node *pop()
{
	if(top==-1)
	{
		printf("Stack UnderFlow");
		exit(0);
	}
	else return sta[top--];
}
int main()
{
	root=create();
	printf("Preorder traversal of tree : ");
	inorder(root);
	cout<<"Enter the element to check : ";
	int a;
	cin>>a;
	c=true;
	struct node *ptr=check(root,0,a);
	cout<<ptr->data<<" "<<co;
	cout<<"\n"<<isCousins(root,4,5);
	return 0;
}

void display(struct node *ptr)
{
	if(ptr==NULL)
	return;
	printf("%d ",ptr->data);
	display(ptr->leftChild);
	display(ptr->rightChild);
}
void preorder(struct node* ptr)
{
	if(ptr==NULL)
    {
        printf("Tree is empty!");
        return;
    }
	push(ptr);
	while(top!=-1);
	{	
	    ptr=pop();
		printf("%d ",ptr->data);
		if(ptr->rightChild!=NULL)
		push(ptr->rightChild);
		if(ptr->leftChild!=NULL)
		push(ptr->leftChild);	
	}
}
void inorder(struct node* ptr)
{
	if(ptr==NULL)
    {
        printf("Tree is empty!");
        return;
    }
    while(1)
    {
    	while(ptr->leftChild!=NULL)
    	{
    		push(ptr);
    		ptr=ptr->leftChild;
		}
		while(ptr->rightChild==NULL)
		{
			printf("1  test ptr->left =%u   ptr->right=%u    ptr->info=%d  \n",ptr->leftChild,ptr->rightChild,ptr->data);
			printf("loop In %d \n",ptr->data);
			if(top==-1)
			return;
			ptr=pop();
		}
		printf("test ptr->left =%u   ptr->right=%u    ptr->info=%d  \n",ptr->leftChild,ptr->rightChild,ptr->data);
		printf("In %d \n",ptr->data);
		ptr=ptr->rightChild;
	    printf("test ptr->left =%u   ptr->right=%u    ptr->info=%d  \n",ptr->leftChild,ptr->rightChild,ptr->data);
	}
}
struct node *create()
{
	struct node *temp=NULL;
	int x;
	printf("Enter the data(0 for no node) : ");
	scanf("%d",&x);
	if(x==0)
	return NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	printf("Enter the Left Child Of %d : \n",x);
	temp->leftChild=create();

	printf("Enter the Right Child Of %d : \n",x);
	temp->rightChild=create();
	
	return temp;
}
