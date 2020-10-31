# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

        
class Solution(object):
    
    def swapPairs(self, head: ListNode) -> ListNode:
        tempNode = head
        if tempNode is None: return None
        
        if tempNode.next is  not None:
            newheadNode= tempNode.next
        else:
            return head
        
        pointerNode = ListNode()
        first=0
        
        while tempNode is not None and tempNode.next is not None:
            
            Node1 = tempNode
            Node2 = tempNode.next
            tempNode= tempNode.next.next

            #put Node2.next which is n3->n4->...nn into Node1.next    
            Node1.next=Node2.next
            #Now put entire Node1 which is n1-n3-n4... into Node2.next . with this step n1 and n2 are swapped.
            Node2.next=Node1
            
            if first==0:
                # In the first iteration save the pointer of new 2nd node  which is node1
                # This pointer node keeps the link between Pari1..Pari2...Pair3....etc.
                pointerNode= Node1
                first=1
            else:
                """ from the second iteration onwards, swap and link the first
                    node from the pair to the second node from last iteration
                """
                pointerNode.next=Node2
                """ Move the pointer 2nd node of the pair"""
                pointerNode=Node1
                
        return newheadNode