''' Approach :

1. Add a dummy node that points to the head of the list.
2. This dummy node will remove the corner cases such as list with one node etc.
3. Initialise a stack and push the nodes onto it until "n". 
4. Add the padding at the end.
5. Remove the previous node and assign the head to the next node.
6. Return the dummy .
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        
        if not head or not n: return
        
        dummy = ListNode()
        dummy.next = head
        node = dummy
        stack = []
        
        while node:
            stack.append(node)
            node = node.next
            
        stack.append(None)
        prev_node = stack[-n - 2]
        next_node = stack[-n]
        prev_node.next = next_node
        return dummy.next
        