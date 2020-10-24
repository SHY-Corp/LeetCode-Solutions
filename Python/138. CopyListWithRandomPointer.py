'''
    LeetCode Link: https://leetcode.com/problems/copy-list-with-random-pointer/

    A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
    Return a deep copy of the list.
    
    The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.

    Example:

        Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
        Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

    Constraints:

        -10000 <= Node.val <= 10000
        Node.random is null or pointing to a node in the linked list.
        The number of nodes will not exceed 1000.

    Solution: 
        
        Step 1: Make a dummy node 
        Step 2: Point the next of head to dummy node and next of dummy node to head.next
        Step 3: Similarly add nodes in between the given nodes of the list
        Step 4: Traverse the dummy list with a pointer p as p = p.next.next
        Step 5: If p.random exists, p.next.random = p.random.next, else p.next.random = None 
        Step 6: Extract the new list and return dummy


    Time Complexity: O(2n)
    Space Complexity: O(n)

'''



"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':

        # dummy = Node(head.val, head)
        if head ==None:
            return None

        p = head
        while(p):
            p_next = p.next
            p.next = Node(p.val, p_next)
            p = p.next.next

        dummy = head.next
        p = head
        while(p):
            if p.random:
                p.next.random = p.random.next
            else:
                p.next.random = None

            p = p.next.next

        k = dummy
        while(k.next):
            k.next = k.next.next
            k = k.next
        return dummy