class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL)
            return NULL;
        
        /*I created 3 pointers. prev points to null and 
          the remaining 2 point to head. 
        */
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=head;
        
        /* I am traversing it till the current element reaches 
           null and applying operations to swap values.
        */
        while(curr!=NULL)
        {
            
         /*  First, I shift temp from head to next element. 
             Then my current node's address points to previous
             instead of next. Now, my prev is equal to the current
             element and current is equal to temp. In the end, I return
             prev which is the reversed linked list.
         */
            temp=temp->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
       return prev; 
    }
};
