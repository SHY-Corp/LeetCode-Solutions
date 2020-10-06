/**
 * The challenge no.215 asks for the kth largest element of an array to be returned.
 * 
 * To solve this problem, the array has to be sorted and then the Kth element from the top will be returned.
 * 
 * To save some processing time, the array only gets sorted for K elements which is slightly faster than sorting all elements.
 */

class Solution {
    public int findKthLargest(int[] nums, int k) {
        if(nums.length == 1) {
            return nums[0];
        }

        for (int indexA = 0; indexA <= k; indexA++) {
            for (int indexB = 0; indexB < nums.length - 1; indexB++) {
                if (nums[indexB] > nums[indexB + 1]) { 
                    swap(nums, indexB, indexB + 1);
                }
            }
        }

        return nums[nums.length - k];
    }

    /**
     * Swaps the values at the given indices in the array.
     * 
     * @param in
     * @param indexA
     * @param indexB
     */
    public void swap(int[] in, int indexA, int indexB) {
        int tmp = in[indexB];
        in[indexB] = in[indexA];
        in[indexA] = tmp;
    }
}