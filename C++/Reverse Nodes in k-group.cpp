/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
 /**
 First create a reverse funcion which just reverses a segment of linked list and then re assigns the pointers accordingly
 so that the reversed list again falls to the place. Then through the driver function just send bits of k segments to the reverse function until 
 the count variable is lesser than k. Here count is the number of nodes in the input list.
  */
  
  
int i; //coz its to be declared for every for loop :(
class Solution {
public:
ListNode* reverse(ListNode * head,ListNode *okay,int k)
{
     ListNode* x=head;
     ListNode*y=nullptr;
     ListNode*z=head;
     
     for(i=0;i<k-1;i++)                         // this gives us the kth node from the start which will be our first node after reversing.
         x=x->next;    
    if(okay!=nullptr)                          // this is the last node of the previous part which was sent to this function. 
      okay->next=x;                           // this joins all count/k parts into one single list
    x=x->next;                                // now we store the first node of next piece.
     for(i=0;i<k;i++)                        // this loop is basic reversing of the list
     {
         y=z->next;
         z->next=x;
         x=z;
         z=y;
     }
    return head ;                      // return the last node in reversed list
}
    
ListNode* reverseKGroup(ListNode* head, int k)
{
 if(k==1)
     return head;
       ListNode* start=head;
       ListNode* nexts=nullptr; ListNode* prev=nullptr;int count=0; ListNode* okay=nullptr;
       for(start=head;start!=nullptr;start=start->next)                                       //counting nodes
            count++;
       start=head;
       if(count>=k)
       for(i=0;i<k-1;i++)
       head=head->next;
       
        while(count-k>=0)
        {
           count=count-k;
           okay=reverse(start,okay,k);     // calling reverse for each bit of k nodes and storing the last node of this piece to be used for next call.
             
              start=start->next;
            
        }

 
       return head;
}
};
