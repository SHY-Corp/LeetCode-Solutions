
/**
 * Given an array of integers containing `n+1` integers where each integer is in the range [1, n] inclusive.
 * There is only one duplicate number in the array, we are supposed to find that duplicate number.
 * 
 * To proceed with this, The "Tortoise and Hare" algorithm is used, which is an algorithm that loops through
 * an array using two pointers; one moving with a speed of one (the tortoise) and the other moving at a speed 
 * of two (the hare). 
 * 
 * These two pointers move by going to the index specified by the current index they are in. So for example,
 * if tortoise was in index 3, with an element of 5, it would move to index 5 next. 
 * 
 * Because the elements in the array are all indexes (when you subtract one), both pointers would always have
 * indexes to move to. (they would be moving in cycles). At some point, they would meet up at some index, the
 * element at this index would be the duplicate element in the array.
 * 
 */

class Solution {

    public static int findDuplicate(int[] nums) {
        int tortoise, hare = tortoise = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        hare = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }

}
