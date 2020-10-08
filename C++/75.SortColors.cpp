/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());        
    }
};
/*
Sample Tests:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Input: nums = [0]
Output: [0]

Input: nums = [1]
Output: [1]
*/
