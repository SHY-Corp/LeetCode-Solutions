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
    ListNode* middleNode(ListNode* head) {
        
        if(head==NULL)
            return head;
        
        /*  I am creating 2 pointers here. The idea is to think in terms 
            of distance and speed. How much distance do my pointers cover
            when one of them is traversing normally and the other is traversing 
            at twice the speed? So when the pointer 'b' traverses twice as fast
            and reaches NULL, pointer 'a' will have traversed half the distance. 
            This way, I know 'a' is in the middle, thus I return it.
        */

        ListNode* a = head;
        ListNode* b = head;
        
        while(b!=NULL && b->next!=NULL)
        {
            a=a->next;
            b=b->next->next;
        }
        return a;
    }
};


/* This is an alternate solution which I worked on. Incrementing a counter when traversing
   the entire linked list, followed by, traversing till half the count and returning that 
   node. In this case- head node. 

if (head == 0 or head->next == 0)
            return head;
        int count = 0;
   ListNode *headTemp = head;
       while (head != 0)
        {
            count++;
            head = head->next;
        }
     head = headTemp;
        for (int i = 0; i < (count / 2); i++)
            head = head->next;
        return head;
 */