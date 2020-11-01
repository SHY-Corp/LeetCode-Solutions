/*Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1.
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.*/

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
    int getDecimalValue(ListNode* head) {
       vector<bool> v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        int ans=0,n=v.size(),t=n;
        for(int i=0;i<t;i++){
            n--;
            if(v[i]){
                ans+=pow(2,n);
            }
        }
        return ans;
    }
};
