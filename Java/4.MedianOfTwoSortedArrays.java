// Given two sorted int arrays, returns the median value of the two.
// The solution aggregates the two arrays together, sorts the result and
// performs the required logic to derive the median value depending
// on the length of the merged array being even/odd.
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int mergedLen = len1 + len2;
        int middle = mergedLen / 2;

        int[] merged = new int[mergedLen];
        System.arraycopy(nums1, 0, merged, 0, len1);
        System.arraycopy(nums2, 0, merged, len1, len2);
        Arrays.parallelSort(merged);

        double result;
        if((mergedLen & 1) == 0) {
            result = (merged[middle - 1] + merged[middle]) / 2d;
        } else {
            result = merged[middle];
        }

        return result;
    }
}
