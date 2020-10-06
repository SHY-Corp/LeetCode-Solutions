/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    /*
        23. Merge K Sorted lists

        You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
        Merge all the linked-lists into one sorted linked-list and return it.

        Input: lists = [[1,4,5],[1,3,4],[2,6]]
        Output: [1,1,2,3,4,4,5,6]
        Explanation: The linked-lists are:
        [
            1->4->5,
            1->3->4,
            2->6
        ]
        merging them into one sorted list:
        1->1->2->3->4->4->5->6
    */

    /*
        This code works by first adding all the values
        from the lists to a single list and then sorting
        those values and using them to create a new ListNode
        with sorted values

        Time complexity: O(nlogn)
        Space complexity: O(n)
    */
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = new ListNode(-1);
        List<Integer> list = new ArrayList<>();
        ListNode current = head;

        for(ListNode first : lists){
            while(first != null){
                list.add(first.val);
                first = first.next;
            }
        }

        Collections.sort(list);
        int i = 0;
        while(i != list.size()){
            current.next = new ListNode(list.get(i));
            current = current.next;
            i++;
        }

        return head.next;
    }
}