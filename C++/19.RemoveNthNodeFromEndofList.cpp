// Title: 19. Remove Nth Node From End of List
// Description: Given the head of a linked list, remove the nth node from the end of the 
//              list and return its head.
// ===========================================================================================
/*
 *
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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* current = head; // move current node 
    ListNode* before = head; 
    // allows for traversing to occur
    for (int i = 0; i < n; i++) {
        current = current -> next;
    }
    // if not at current node it will then point to the next node - for traversing
    if (!current) {
        return head -> next;
    }
    // traverses both pointers until the current node reaches the end of the list
    while (current -> next != NULL) {
        before = before -> next;
        current = current -> next;
    }
    before -> next = before -> next -> next;
    return head;
    }
};