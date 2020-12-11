// problem - 81. Search in Rotated Sorted Array II

/*
    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
    (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

    You are given a target value to search. If found in the array return true, 
    otherwise return false.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // simple linear search
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) return true;
        }
        
        return false;
    }
};

// Time Complexity = O(n) [where n is size of nums(length)]
// Space Complexity = O(1)