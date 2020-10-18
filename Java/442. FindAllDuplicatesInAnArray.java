//This is Problem 442. Find All Duplicates in an Array(Medium) on leetcode.
//Complexity O(n) time and O(n) space complexity.

//Approach
//- W can easily remove duplicates from an array if we knew that element was visited before or not.
// to check that, we use HashMap. Hashmaps are really fast and stores key-value pairs. with unique keys.
//- Now , we also create a empty arraylist to add first occurences of each element.
//- Then we iterate through the array and, check if the HashMap already contains the element we are trying to add, if so we just go into new iteration.
//- If the element is being visited for the first time, then we add it to oyr arraylist.
//- After the loop ends, we would have an arraylist containing only unique elements and we return that list.

class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        List<Integer> list = new ArrayList();
        
        for(int i = 0 ; i<nums.length;i++){
            if(!map.containsKey(nums[i])){
                map.put(nums[i],1);
            }
            else{
                list.add(nums[i]);
            }
        }
        return list;
        
    }
}
