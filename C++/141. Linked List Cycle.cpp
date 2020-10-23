/* 
 Problem #141. Linked List Cycle
 
    Solution explanation:
    
    Let's say we have a linked list as follows:
        1 -> 2-> 3 -> 4 -> 5 
    Now, let's consider the last node. Instead to pointing to NULL, it points to Node 3. This forms a loop in the linked list.
    
    In order to detect it, there many methods such as Hashing, or keeping in check a third variable, say flag. But the most efficient one is:
        Floyd's Cycle-Finding Algorithm, also known as Tortoise-Hare Algorithm.
    
    This algorithm states that we maintain two pointers, say a slow pointer and a fast pointer, initially pointing to head pointer.
    The slow pointer moves one step at a time and the fast pointer moves two step at a time.
    
    The idea is simple, while any one of the pointer becomes NULL or the next of fast pointer becomes NULL we loop the linked list.
    If in-case, both the pointer becomes equal, we return true, stating that there is a loop else we return false.
        
*/


#include <iostream>
using namespace std;

/* We create a structure for our Node consisting of two parts, a data part and a next part linking to the next node */
struct ListNode{
    int data;
    ListNode(int x){
        data=x;
    }
    ListNode *next=NULL;
};

/* This is the Solution class  */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *slow=head;
        ListNode *fast=head;
        
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return 1;
        }
        return 0;
    }
};