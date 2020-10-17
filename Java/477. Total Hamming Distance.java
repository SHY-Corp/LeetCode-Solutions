/**
 * Question:
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * <p>
 * Now your job is to find the total Hamming distance between all pairs of the given numbers.
 * <p>
 * Example:
 * <p>
 * Input: 4, 14, 2
 * Output: 6
 * Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
 * showing the four bits relevant in this case). So the answer will be:
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
 * <p>
 * Note:
 * 1. Elements of the given array are in the range of 0 to 10^9
 * 2. Length of the array will not exceed 10^4.
 */
class Solution {
    public int totalHammingDistance(int[] nums) {
        int totalHDistance = 0;
        int noOfOne;
        int noOfZero;
        int arrayLength = nums.length;

        // Iterate over each bit
        for (int i = 0 ; i < 32 ; ++i) {
            noOfOne = 0;
            noOfZero = 0;
            // Iterate over each array element
            for (int j = 0 ; j < arrayLength ; ++j) {
                if ((nums[j] & (1 << i)) == (1 << i)) {
                    ++noOfOne;
                } else {
                    ++noOfZero;
                }
            }
            totalHDistance += noOfOne * noOfZero;
        }
        return totalHDistance;
    }
}