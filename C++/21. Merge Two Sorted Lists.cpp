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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

       ListNode * head=NULL;
       //if anyone of them is empty
        if(l1==NULL) return l2;
        else if(l2==NULL) return l1;

        //assigning head
        if(l1->val<l2->val) {
            head=l1;
            l1=l1->next;
        }
        else {
            head=l2;
            l2=l2->next;
        }
        //temp is an iterator
        //it will iterate and change the links as per the requirement
        ListNode * temp=head;
        while(l1 && l2){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
            else {
                temp->next=l2;
                temp=temp->next;
                l2=l2->next;
            }
        }
        if(l1!=NULL){
            while(l1){
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
        }
        else if(l2!=NULL){
            while(l2){
            temp->next=l2;
            l2=l2->next;
            temp=temp->next;
            }
        }

        return head;

    }
};
