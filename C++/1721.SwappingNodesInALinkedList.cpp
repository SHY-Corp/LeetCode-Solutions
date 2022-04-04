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
    ListNode* swapNodes(ListNode* head, int k) {
        /* //brute-force approach
        vector<ListNode*> v;

        ListNode* temp = head;
        while(temp)
        {
            v.push_back(temp);
            temp = temp->next;
        }

        swap(v[k-1]->val, v[v.size()-k]->val);

        return head;
        */

        // A better approach:
        //TC: O(N), required for iterating over the linked list, where N is the number of nodes
        //SC: O(1), since only constant space is used.

        /*
        ListNode* kthNode = NULL;
        ListNode* kthNodeFromEnd = NULL;
        ListNode* temp = head;

        int n = 0, index = 0;
        while(temp)
        {
           temp = temp->next;
            n++;
        }
        temp = head;
        while(temp)
        {
            if(index==k-1)
                kthNode = temp;
            if(index==n-k)
                kthNodeFromEnd = temp;
            if(kthNode!=NULL && kthNodeFromEnd!=NULL)
                break;

            temp = temp->next;
            index++;
        }
        swap(kthNode->val, kthNodeFromEnd->val);
        return head;
        */

        //Above approach further optimized to reduce time:
        //TC: O(N) While this complexity is same as previous, the constant factor is reduced by half.
        //SC: O(1), since only constant space is used

        ListNode* kthNode;
        ListNode* kthNodeFromEnd = head;
        ListNode* temp = head;

        //traversing the temp node till k
        while(--k)
        {
            temp = temp->next;
        }
        //initializing the kthNode with current temp node
        kthNode = temp;
        while(temp->next!=NULL)
        {
            temp = temp->next;
            //the gap between kthNodeFromEnd and current temp node will be k, since we've already iterated
            //temp node k times in the previous step, so the gap will always be k till temp reaches NULL and
            //kthNodeFromEnd is correctly positioned
            kthNodeFromEnd = kthNodeFromEnd->next;
        }
        //swapping the values
        swap(kthNode->val, kthNodeFromEnd->val);
        return head;
    }
};
