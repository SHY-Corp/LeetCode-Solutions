/**Merge two sorted linked lists and return it as a new list.
*The new list should be made by splicing together the nodes of the first two lists.

*Example:

*Input: 1->2->4, 1->3->4
*Output: 1->1->2->3->4->4

*The specific idea is to create a new linked list, then compare the element values in the two linked lists, and link the smaller one to the new linked list.
*Since the lengths of the two input linked lists may be different, there will be a linked list to insert all elements first.
*Then another unfinished linked list is directly linked to the end of the new linked list. 

*C++ solution: */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
