"""
25. Reverse Nodes in K-Group

The program uses a variable(finchk) to check if there are enough(k) nodes remaining to reverse.
If so, it reverses connection(k-1) between each pair of nodes(k) and moves to next group.
If not, it returns the current linked list as answer.
"""

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy, dummy.next = ListNode(0), head
        prev, cur = dummy, dummy.next
        finchk = cur
        
        while 1:
            for _ in range(k):
                if not finchk: return dummy.next
                finchk = finchk.next
            for _ in range(k-1):
                cur.next.next, cur.next, prev.next = prev.next, cur.next.next, cur.next
            prev, cur = cur, cur.next
        return dummy.next
