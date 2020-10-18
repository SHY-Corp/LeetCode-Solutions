/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *prev,*start=l1;
        int sum=0,carry=0;
        while(l1!=NULL && l2!=NULL)
        {
            sum=l1->val+l2->val+carry;
            
            l1->val=(sum)%10;
            carry=sum/10;
            prev=l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            sum=l1->val+carry;
            l1->val=(sum)%10;
            carry=sum/10;
            prev=l1;
            l1=l1->next;
        }
        l1=prev;
        while(l2!=NULL)
        {
            sum=l2->val+carry;
            l1->next=new ListNode((sum)%10);
            
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(carry!=0)
        {
            l1->next=new ListNode((carry)%10);
            carry/=10;
            l1=l1->next;
        }
        return start;
    }
};
