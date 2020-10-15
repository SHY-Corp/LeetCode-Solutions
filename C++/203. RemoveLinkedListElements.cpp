/*
** LeetCode Problem 203. Remove Linked List Elements
** Url: https://leetcode.com/problems/remove-linked-list-elements/
** Statement:
** Remove all elements from a linked list of integers that have value val.
**
** Example:
** Input:  1->2->6->3->4->5->6, val = 6
** Output: 1->2->3->4->5
*/

// Structure for each node

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        // Return if input list is empty
        if (head == nullptr) {
            return head;
        }

        ListNode* curr = head;

        // Traverse through the list
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                // If next element has the value to be removed
                // take a temporary reference to it to free it
                // and prevent memory leak. And, update the
                // next pointer of the current node to skip
                // the matched value
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        if (head->val == val) {
            // If head contains the value to be removed,
            // the update the list to remove it.
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        return head;
    }
};