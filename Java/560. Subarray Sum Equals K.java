/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Example 2:
Input:nums = [0,0,0,0], k = 0
Output: 10
*/

class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0, sum = 0;
        HashMap < Integer, Integer > map = new HashMap < > ();
        map.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (map.containsKey(sum - k))
                count += map.get(sum - k);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        return count;
    }
}



/* Explantion/Approach:
The trick here is to maintain HashMap<Integer, Integer> which stores frequency of prefix sums as key and its freuqency as value. The question if kindof extension of zero sum subarray problem. See this video: https://www.youtube.com/watch?v=PSpuM9cimxA (zero sum subarray).
*/