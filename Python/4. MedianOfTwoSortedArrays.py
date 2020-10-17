"""
Problem :
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n))


Procedure :
1. To find the median of the two arrays, we need the merged and sorted array of the given two arrays.
Since the input two arrays are already sorted, we can merge the two sorted array by using a simple merge algorithm.
2. Then we can find the median by just get the middle index of the merged array,if the length of merged array is odd.
Else can find the median by calculating the average of two middle indexes of the merged array.

"""


class Solution:
    """
    This program takes two sorted arrays and retuen the median of the combined arrays.
    """

    def mergeArrays(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        This function takes two sorted arrays and retuen the merged and sorted array.
        """
        i = 0
        j = 0
        merge_array = []

        # while i is less then length of nums1 or j is less than length of nums2
        while (i < len(nums1) or j < len(nums2)):

            # if all elements from nums1 have been merged, then merge the rest of elements nums2 and break the loop
            if (i >= len(nums1)):
                merge_array += nums2[j:]
                break

            # if all elements from nums2 have been merged, then merge the rest of elements nums1 and break the loop
            elif (j >= len(nums2)):
                merge_array += nums1[i:]
                break

            # else add the smallest one to the merge_array
            else:
                if (nums1[i] <= nums2[j]):
                    merge_array.append(nums1[i])
                    i += 1
                else:
                    merge_array.append(nums2[j])
                    j += 1
        return (merge_array)

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        combine = self.mergeArrays(nums1, nums2)
        mid = len(combine) // 2

        # if length is even return the average of two middle indexes of the combined array.
        if (len(combine) % 2 == 0):
            return (combine[mid - 1] + combine[mid]) / 2

        # if length is odd return the middle index of the combined array.
        else:
            return combine[mid]