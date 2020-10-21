/*

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]

Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively. 
It doesn't matter what values are set beyond the returned length.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0; // return 0 if no element in the array
        
        int last = nums[0]; // this variable store the last unique element
        int idx = 1; // to maintain index of the array
        
        // first element will never change, so loop will start from element 1
        for(int i = 1; i < nums.size(); i++) {
            if(last != nums[i]) { // checking if last inserted element is same as current element
                nums[idx++] = nums[i]; // store nums[i] in newly indexed array if its not duplicate
                last = nums[i]; // storing current element for future checking
            }
        }
        
        return idx; // value of idx is the length
    }
};