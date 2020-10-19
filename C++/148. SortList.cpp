/**
 *Implementation of an N * log (n) algorithm for sorting a linked list, with node as defined below, using MergeSort being used.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 * For Example:
 * Input: [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 */
class Solution {
public:
    void mergeSort(ListNode** headRef) 
    { 
        ListNode* head = *headRef; 
        ListNode* a; 
        ListNode* b; 
  
        /* Base case -- length 0 or 1 */
        if ((head == NULL) || (head->next == NULL)) { 
            return; 
        } 
  
        /* Split head into 'a' and 'b' sublists */
        frontBackSplit(head, &a, &b); 
  
        /* Recursively sort the sublists */
        mergeSort(&a); 
        mergeSort(&b); 
  
         /* answer = merge the two sorted lists together */
        *headRef = sortedMerge(a, b); 
    } 
    
    void frontBackSplit(ListNode* source, ListNode** frontRef, ListNode** backRef) 
    { 
        ListNode* fast; 
        ListNode* slow; 
        slow = source; 
        fast = source->next; 
  
        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != NULL) { 
            fast = fast->next; 
            if (fast != NULL) { 
                slow = slow->next; 
                fast = fast->next; 
            }   
        } 
  
        /* 'slow' is before the midpoint in the list, so split it in two  
        at that point. */
        *frontRef = source; 
        *backRef = slow->next; 
        slow->next = NULL; 
    } 
    
    ListNode* sortedMerge(ListNode* a, ListNode* b) 
    { 
        ListNode* result = NULL; 
  
        /* Base cases */
        if (a == NULL) 
            return (b); 
        else if (b == NULL) 
            return (a); 
  
        /* Pick either a or b, and recur */
        if (a->val <= b->val) { 
            result = a; 
            result->next = sortedMerge(a->next, b); 
        } 
        else { 
            result = b; 
            result->next = sortedMerge(a, b->next); 
        } 
        return (result); 
    } 
    
    ListNode* sortList(ListNode* head) {
        mergeSort(&head);
        return head;
    }
};
