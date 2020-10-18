// Java Solutions (Naive and Two pointer approach) for 19. Remove Nth Node From End of List
/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

//Naive Approach
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        ListNode temp=head;
        ListNode temp1=head;
        ListNode secondlast=head;
        int count=1;
        while(head.next!=null){
            head=head.next;
            count++;
        }
        if(count==0 || count==1)
            return null;
        else if(count-n+1==count){
            while(secondlast.next.next!=null)
                secondlast=secondlast.next;
            secondlast.next=null;
            return temp1;
        }
        else if(count-n+1==1){
            temp.val=temp.next.val;
            temp.next=temp.next.next;
            return(temp1);
        }
        else{
            n=count-n;
            for(int i=1;i<=n;++i){
                temp=temp.next;
            }
            temp.val=temp.next.val;
            temp.next=temp.next.next;
            return(temp1);
        }
    }
}

//Two Pointer Approach (Single pass)
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // First pointer will point to the head of the linked list 
        Node one = head; 
  
        // Second pointer will point to the Nth node from the beginning 
        Node two = head; 
        for (int i = 0; i < n; i++) { 
  
            //if n is less than or equal to the number of nodes in list
            if (two.next == null) { 
  
                // If count =  n i.e. delete the head node 
                if (i == n - 1) 
                    head = head.next; 
                return; 
            } 
            two = two.next; 
        } 
  
        // Increment both the pointers one by one until second pointer reaches the end 
        while (two.next != null) { 
            one = one.next; 
            two = two.next; 
        } 
  
        // One must be pointing to the Nth node from the end by now 
        // So delete this node
        one.next = one.next.next; 
    }
}
