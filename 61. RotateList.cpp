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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
             return NULL;
        int length=0;
        ListNode* temp=head;
        ListNode* lasts;//This is pointer pointing to the last node
        while(temp!=NULL)
        {
            if(temp->next==NULL)
                lasts=temp;
            length++;
            temp=temp->next;
        }
        k=k%length;
        if(k==0)
             return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* rethead;//This is pointer for final head;
        for(int i=1;i<=k+1;i++)
         fast=fast->next;
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        rethead=slow->next;
        slow->next=NULL;
        lasts->next=head;
        return rethead;//Returning final pointer
    }
};
