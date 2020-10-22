Problem: Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9


The idea here is to store all the numbers in a set for easy access. For each number checking whether the subsequent number is present.
Increasing the length depending on the numbers present.

Code:

class Solution {
    public int longestConsecutive(int[] nums) {
        //To store the list of all numbers
        HashSet<Integer> set = new HashSet<>();
        for(int a:nums)
            set.add(a);
	// used to get the longest length of consecutive length
        int ans = 0;
        for(int i =0;i<nums.length;i++){
	    // To check if the current number is already counted	
            if(!set.contains(nums[i]-1)){
                int j = nums[i];
		//Incrementing the count till the subsequent numbers are found
                while(set.contains(j))
                    j++;
		//Storing the longest length.
                ans = Math.max(ans, j-nums[i]);
            }
        }
        return ans;
    }
}