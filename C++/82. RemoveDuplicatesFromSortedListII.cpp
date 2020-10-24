//PROBLEM - 82.Remove Duplicates From Sorted List II
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
Return the linked list sorted as well.

Input:  [1,2,3,3,4,4,5]
Output: [1,2,5]
*/

//LOGIC
/*
Declare a boolean variable and initialse it to false. 
Traverse the list from the head node.  Whenever current node has duplicates set this boolean variable to true.
If data of next node is same as current node then delete the next node. 
If data of next node is NOT same as current node && boolean variable is true, then delete the current node.
Before we delete a node, we need to store next pointer of the node.
*/

// Time Complexity: O(n)

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
        ListNode* current = head;
        ListNode* prev = head;  // initialise both previous and current node to head
        ListNode* tmp; 
        
        bool flag=false;  
        while (current != NULL) {
           // compare current node with next node
            if (current->next!=NULL && current->val == current->next->val) {
                /*val at current node is same as val at next node. So delete the next node*/
                flag=true;
                tmp = current->next->next;
                delete (current->next);
                current->next = tmp;  
            }
            else { /*val at current node is not equal to val at next node*/
                if(flag) { 
                    /* val at current node is not equal to val at next node, but current node had dupliactes in original list
                      So, all the occurences of duplicates must be deleted
                    */
                    if(current==head) { /*node to be deleted is starting node*/
                        tmp=head->next;
                        delete head;
                        head = tmp;
                        prev=head;
                        flag=false;
                        current=head; 
                        continue;
                    }
                    else {
                        tmp = prev->next->next;
                        delete (prev->next); 
                        prev->next = tmp;
                        flag=false; 
                    }
                }
                else {   // no deletion
                    prev=current;  
                }

                current = prev->next; //moving to next node in the list
            }
        }
        return head;
    }
};