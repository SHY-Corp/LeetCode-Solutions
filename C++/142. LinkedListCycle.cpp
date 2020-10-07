//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//There is a cycle in a linked list if there is some node in the list that can be reached again
//by continuously following the next pointer. 

//C++ code to detect the cycle and find the node where the cycle begins in the linked list
//It uses floyd's cycle finding algorithm
//It contains an O(1) solution to detect cycle in a linked list and return the node where the cycle starts

//Definition for LinkedList node
struct node
{
	int val;
	node *next;
	node(int x)
	{
		val=x;
		next=nullptr;
	}
};

class Solution
{
	public:
    	node *detectCycle(node *head)
	{
	        node *slow,*fast;
		bool flag=1;
	        if(head==NULL)
		   return NULL;
	        slow=head;
		fast=head;
	        while(slow and fast and fast->next)
	        {
			slow=slow->next;
	        	fast=fast->next->next;
	        	if(slow==fast)
			{
	            	   flag=0;break;
	        	}
		}
	        if(!flag)
	        {
	            slow=head;
	            while(slow!=fast)
	            {
	                slow=slow->next;
			fast=fast->next;
		    }
	            return slow;
		}		
	        else
	        {
	            return NULL;
	        }
    	}
};
