# Function findPeakElement finds receives an array
# and searches for an element considered a peak (greater than its neighbors )
class Solution(object):

    def findPeakElement(self, arr):
        """
        finds the peak element in the array
        :param arr: List[int]
        :return: the peak element int
        """

        # checks if the array is to small therefore no real need to check
        if len(arr) == 1:
            return 0
        # dealing with two is only a single case
        elif len(arr) == 2:
            if arr[0] > arr[1]:
                return 0
            else:
                return 1

        # peak is at the beginning
        if arr[0] > arr[1]:
            return 0

        # goes though the array and finds a peak
        for i in range(1, len(arr) - 1):
            if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
                return i

        # peak is at the end
        return len(arr) - 1

