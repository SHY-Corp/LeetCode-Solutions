'''Approach :

1. Create a new list "temp" containing a empty list node, i.e. value is None, as the head node
2. Set the next pointer of the head node to the node with a smaller value in the given two linked lists. For example l1's head node is smaller than l2's then set the next pointer of the new list's head node to l1.
3. Assign l1's head record to l1's current head node's next node.
4. Repeat step 2 until one of the remaining two linked lists have no nodes left.
5. Assign l1's tail record to keep the information of the remaining L2, i.e. point it to L2.
6. Return l1's head nodes's next record.'''



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = None
        temp  = ListNode()
        
        while l1 and l2 : 
            
            if l1.val > l2.val : 
                center = l2 
                l2 = l2.next
                
            else : 
                center = l1
                l1 = l1.next
                
            if not head :
                head = center
                temp = head
                
            else: 
                temp.next = center
                temp = temp.next
        
        if head : 
            if l1 : 
                temp.next = l1
            if l2 : 
                temp.next = l2
                
        else: 
            if l1 :
                head = l1
            else:
                head = l2
        
        return head
        