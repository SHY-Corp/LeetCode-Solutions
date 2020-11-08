// problem - 445. Add Two Numbers II

/*
    You are given two non-empty linked lists representing two non-negative integers. 
    The most significant digit comes first and each of their nodes contain a single digit. 
    Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

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

    // helper function to reverse a linked list 
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *prev = head, *curr = head->next, *root = nullptr;
        
        while(curr != nullptr) {
            ListNode *temp = curr->next;
            if(temp == nullptr) root = curr;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head->next = nullptr;
        
        return root;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reversing both the linked list
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        // head for solution list
        ListNode *head = nullptr;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr) {
            // values are assigned when the pointer is not null
            int val1 = 0, val2 = 0;
            if(l1 != nullptr) val1 = l1->val;
            if(l2 != nullptr) val2 = l2->val;
            
            int sum = val1 + val2 + carry;
            int digit = sum%10;
            carry = sum/10;
            
            ListNode *temp = new ListNode(digit, head);
            head = temp;
            
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }

        // to handle the left over carry        
        if(carry != 0) {
            ListNode *temp = new ListNode(carry, head);
            head = temp;
        }
        
        return head;
    }
};

// Time Complexity = O(N) Linear Time
// Space Complexity = O(N) Linear Time (this is because we store solution list)