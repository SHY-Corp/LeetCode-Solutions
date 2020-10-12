"""
Goal:   You are given two non-empty linked lists representing two non-negative integers. 
        The digits are stored in reverse order, and each of their nodes contains a single digit. 
        Add the two numbers and return the sum as a linked list.
        You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Procedure:
    ==> Idea is to find the sum of two numbers, which has been arranged in reverse order in a linked list.
    -> Create a dummy node to start with a new resultant linked list.
    -> Get the value from current nodes of the two linked lists if present, otherwise consider default value 0.
    -> Add the values along with the carry value.
        -> Carry value: Suppose a result of addition is 24, then the ten's place value, here it is 2, is stored in the carry variable.
        -> The remaining value, here being 4, is then added as a result to the current sequence of resulting linked list node
    -> Create a new next node for further addition.
    -> Continue from step 2 as long as there is either values present in the two linked list otherwise if carry is not 0.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        rNode = ListNode()
        res = rNode
        carry = 0
        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            
            value = v1 + v2 + carry
            carry = value // 10
            value %= 10
            res.next = ListNode(value)
            
            res = res.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            
        return rNode.next
            
            
        
