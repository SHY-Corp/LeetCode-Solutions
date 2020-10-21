"""
Problem:
--------

Design a data structure that supports the following two operations:

- `void addNum(int num)`: Add a integer number from the data stream to the data structure.
- `double findMedian()`: Return the median of all elements so far.
"""


class MedianFinder:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.list = []

    def addNum(self, num: int) -> None:
        # Traverse through the list and check if `num` > ith element
        # If yes, insert `num` in that index
        # This keeps the list sorted at all times
        for i in range(len(self.list)):
            if num > self.list[i]:
                self.list.insert(i, num)
                return

        # If `num` is the largest element or is the first one to be added
        self.list.append(num)

    def findMedian(self) -> float:
        # Find index of the middle element (floor division by 2)
        mid_index = len(self.list) // 2

        if len(self.list) % 2 == 0:
            # If number of elements = EVEN
            # Return average of the middle 2 elements
            return (self.list[mid_index - 1] + self.list[mid_index]) / 2
        else:
            # If number of elements = ODD
            # Return the middle element
            return self.list[mid_index]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
