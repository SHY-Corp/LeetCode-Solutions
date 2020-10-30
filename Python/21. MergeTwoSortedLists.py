"""
This program takes merges two sorted lists
"""

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        if not l1 and not l2:
            return ListNode(0).next
        if not l1:
            return l2
        if not l2:
            return l1

        result = []
        while l1 and l2:
            if l1.val <= l2.val:
                result.append(l1)
                l1 = l1.next
            else:
                result.append(l2)
                l2 = l2.next

        while l1:
            result.append(l1)
            l1 = l1.next

        while l2:
            result.append(l2)
            l2 = l2.next

        for i in range(len(result)-1):
            result[i].next = result[i+1]
        result[-1].next = None
        return result[0]


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def next_list(self, next_list):
        self.next = next_list


a = ListNode(2)
a1 = ListNode(3)
a.next = a1
b = ListNode(1)
b1 = ListNode(1)
b.next = b1

print(Solution().mergeTwoLists(a, b))
