/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> lists = new ArrayList<>();
        for(int i=0; i<(1<<nums.length); i++){
            List<Integer> list = new ArrayList<>();
            for(int j=nums.length-1; j>=0; j--){
                int mask = 1<<j;
                
                if((i&mask) != 0){
                    list.add(nums[nums.length-1-j]);
                }
            }
            lists.add(list);
        }
        
        return lists;
    }
}
