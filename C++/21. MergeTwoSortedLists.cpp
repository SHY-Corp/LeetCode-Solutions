/*

21. Merge Two Sorted Lists

https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

*/


/*

Solution:

-> Simple and short recursive code that works by pointer manipulation. 
-> Uses O(1) space apart from stack usage of recursive function calls

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		if(l1 -> val < l2 -> val){
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		} else{
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;
		}
    }
};
