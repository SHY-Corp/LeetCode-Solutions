class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL)
            return NULL;
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=head;
        
        while(curr!=NULL)
        {
            temp=temp->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
       return prev; 
    }
};
