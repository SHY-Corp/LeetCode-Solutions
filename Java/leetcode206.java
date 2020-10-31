/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode forw = null;
        ListNode curr = head;
        
        while (curr != null) 
        {
            forw = curr.next;
            
            curr.next = prev;
            
            prev = curr;
            curr = forw;
        }
        return prev;
    }
}