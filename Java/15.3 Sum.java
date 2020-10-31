/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

Example 1:
----------
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
----------
Input: nums = []
Output: []

Example 3:
----------
Input: nums = [0]
Output: []
 
Constraints:
------------
0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums.length < 3) return new ArrayList<>(); // if nums less than 3 element
        Arrays.sort(nums); // sort array
        Set<List<Integer>> set = new HashSet<>();
        for (int i = 0; i < nums.length - 2; i++) {
            //initialize low and high pointers
            int j = i + 1; //j is the low pointer
            int k = nums.length - 1;//k is the high pointer
            
            //while low pointer is less than high pointer
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; //sum of 3 elements in the array
                if (sum == 0) set.add(Arrays.asList(nums[i], nums[j++], nums[k--]));//if sum=0 ,we have the 3 required elements
                else if (sum > 0) k--; //if sum>0, move the high pointer to the left 
                else if (sum < 0) j++; //if sum<0, move the low pointer to the right
            }

        }

        return new ArrayList<>(set);
    }
}
/*
Short Explanation
------------------
Declare a set
	 Sort the array
	 start with one loop (say i) which selects the first number 'a' from sorted array
	 then declare two variables say 'j' and 'k'
	 j(low pointer) will point to i+1 index and k(high pointer) will point to last index of the sorted array
	 array[j] will denote second number say 'b'
	 array[k] will denote third number say 'c'
	 start the second while loop and run until j(low pointer) crosses high one i.e j < k
	 sum = array[i]+array[j]+array[r]
	 if sum = 0
		  then store these numbers as list in the set
	 else if sum < 0
		  move the low pointer forward i.e j++
	 else
		 move the high pointer backward or say towards j i.e k--
		 Since sum > 0 and the array is already sorted(ascending order), so if 'k' moves towards 'j'
		 sum could minimize.
*/
