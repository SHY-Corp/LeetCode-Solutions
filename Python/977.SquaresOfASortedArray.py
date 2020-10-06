# Having sorted array A of negative and positive integers, sortedSquares
# returns sorted array of squared elements from A
#
# Example:
# A = [-4, -1, 3, 5]
# result = [1, 9, 16, 25]
#
class Solution:
    def sortedSquares(self, array: List[int]) -> List[int]:
        squared_array = [x*x for x in array]
        sorted_array = []

        left = 0
        right = len(squared_array) - 1

        while left <= right:
            left_item = squared_array[left]
            right_item = squared_array[right]

            if left_item > right_item:
                sorted_array.append(left_item)
                left += 1
                continue

            sorted_array.append(right_item)
            right -= 1

        return list(reversed(sorted_array))
