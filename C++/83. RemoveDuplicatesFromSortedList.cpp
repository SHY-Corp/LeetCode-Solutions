/*
Problem: Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

/* 

Solution: _Iterative approach_

*Let us call the current node to be "cur" and the immediate next node to cur as "temp".*

Now, traverse the linked list from the starting point(head) and check if the immediate next node ie., (temp) is equal 
to the current node ie., (cur) or not.
1) If the temp is not equal to the cur, then proceed forward.
2) Otherwise, assign the next pointer of "cur" to the next pointer of "temp" and assign the next pointer of "temp" to be NULL.

The traversal terminates once cur == NULL (or) cur->next == NULL.
It's because the traversal would have reached the end of the linked list when cur == NULL (or) cur->next == NULL.

Corner case:
** If the head is a NULL pointer then, we will return the head just as it is.

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
    ListNode* deleteDuplicates(ListNode* head) {

    	if(head == NULL){
    		return head;
    	}

    	ListNode* cur = head;

        while(cur!=NULL && cur->next!=NULL){

        	ListNode* temp = cur->next;

        	if(cur->val == temp->val){
        		cur->next = temp->next;
        		temp->next = NULL;
        	}

        	else{
        		cur = cur->next;
        	}

        }

        return head;
    }


};