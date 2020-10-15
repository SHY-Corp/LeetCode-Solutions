# Function findPeakElement finds receives an array and checks if
# the array contains a duplicate of two numbers
class Solution(object):

    def ContainsDuplicate(self, arr):
        """
        checks if the array contains a duplicate
        :param arr: List[int] a list of numbers
        :return: True or False if it contains a duplicate
        """

        # a set to contains numbers we have seen
        taken_numbers = {}

        # goes through all values in the arr
        for i in arr:
            # checks if the number has already been seen
            if i in taken_numbers:
                return True
            # adds the number since it hasn't been seen
            else:
                taken_numbers[i] = i

        # we have not seen any duplicates
        return False
