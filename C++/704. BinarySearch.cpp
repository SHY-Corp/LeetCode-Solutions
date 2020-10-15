/* BINARY SEARCH */

/*
Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.
*/

/*
Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int _size = nums.size();
        int _left = 0;
        int _right = _size-1;
        
        int _middle;
        while(_left <= _right)
        {
            _middle = (_left+_right)/2;
            if(target > nums[_middle])
                _left = _middle+1;
            else if(target < nums[_middle])
                _right = _middle-1;
            else
                return _middle;
        }
        
        return -1;
    }
};