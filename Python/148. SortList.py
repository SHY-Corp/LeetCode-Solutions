#Problem: Given the head of a linked list, return the list after sorting it in ascending order.
#Approach: We use merge sort and account for the use of a linked list to solve this

class Solution(object):
    #returns the middle node of the linked list referenced by head
    def getMiddle(self,head):
        double_step = head
        single_step = head
        prev_single = head
        while (double_step is not None) and (double_step.next is not None):
            prev_single = single_step
            single_step = single_step.next
            double_step = double_step.next.next
        prev_single.next = None
        return single_step    

    #merges in sorted order two sorted linked lists
    def merge(self,head_of_list1, head_of_list2):
        temp = ListNode(0);
        temp_head = temp;
        while head_of_list1 and head_of_list2:
            if head_of_list1.val < head_of_list2.val:
                temp.next = head_of_list1
                head_of_list1 = head_of_list1.next
            else:
                temp.next = head_of_list2
                head_of_list2 = head_of_list2.next
            temp = temp.next
        if head_of_list1:
            temp.next = head_of_list1
        elif head_of_list2:
            temp.next = head_of_list2
        return temp_head.next
        """
        :type head: ListNode
        :rtype: ListNode
        """
    def sortList(self, head):
        if (head is None) or (head.next is None):
            return head
        middle = self.getMiddle(head)
        left = self.sortList(head)
        right = self.sortList(middle)
        return self.merge(left, right)
