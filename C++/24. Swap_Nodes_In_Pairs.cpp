//24. Swap Nodes in Pairs
//Given a linked list, swap every two adjacent nodes and return its head.

//You may not modify the values in the list's nodes. Only nodes itself may be changed.

/* For example:
	Input: head = [1,2,3,4]
	Output: [2,1,4,3]
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
       
        ListNode* newhead = head->next;
        ListNode* temp = newhead->next;
        newhead->next = head;
        head->next = swapPairs(temp);
        return newhead;
    }
};