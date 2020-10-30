/*
    Question 143: Reorder List: Given a singly linked list L: L0→L1→…→Ln-1→Ln,
    reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

    You may not modify the values in the list's nodes, only nodes itself may be changed.

    Example 1:
        Given 1->2->3->4, reorder it to 1->4->2->3.
    
    Example 2:
        Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

*/


/**
 * Definition for singly-linked list.
*/ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr) return;
        
        ListNode* cur=head;
        int count=1;
        stack<ListNode*> Pointers;
        Pointers.push(cur);
        
        while(cur->next!=nullptr) {
            cur=cur->next;
            Pointers.push(cur);
            count++;
        }
        if(count<=2) return;
        cur=head;
        
        while(Pointers.size()>count/2+1){
            
            ListNode* temp=cur->next;
            cur->next = Pointers.top();
            Pointers.pop();
            cur=cur->next;
     
            cur->next=temp;
            cur=temp;
        }
        
        if(count%2==0){
            cur=cur->next;
        }
        cur->next=nullptr;
    }
};