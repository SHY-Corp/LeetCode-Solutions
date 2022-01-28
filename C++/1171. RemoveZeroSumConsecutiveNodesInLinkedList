/*
Title: Remove Zero Sum Consecutive Nodes from Linked List
Link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

Description: Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
             After doing so, return the head of the final linked list.  You may return any such answer.

Examples:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Input: head = [1,2,3,-3,-2]
Output: [1]
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

class Solution 
{
public:
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        // Set up temporary ListNode* to guarantee access to head by end of function
        ListNode* temp = new ListNode(0, head);
        map<int, ListNode*> sumMap;
        int sum = 0;
        sumMap[sum] = temp;
        
        while (head)
        {
            // Add up values as linked list is traversed
            sum += head->val;
            
            // If the sum reached is already in the map, consecutive nodes add up to zero
            if (sumMap.count(sum))
            {
                ListNode* traverse = sumMap[sum]->next;
                sum += traverse->val;
                map<int, ListNode*>::iterator it;
                
                // Delete consecutive nodes that add up to zero in linked list
                while (traverse != head)
                {
                    it = sumMap.find(sum);
                    sumMap.erase(it);
                    traverse = traverse->next;
                    sum += traverse->val;
                }
                
                sumMap[sum]->next = head->next;
            }
            // If current sum hasn't been reached yet, insert into map
            else
                sumMap[sum] = head;
            
            head = head->next;
        }
        
        // Return linked list with no consecutive nodes summing to zero
        return temp->next;
    }
};
