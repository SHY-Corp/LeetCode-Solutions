/*
Problem 961 - N-Repeated Element in Size 2N Array

You are given an integer array nums with the following properties:
nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.
*/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // Iterate over nums
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                // If we find a repeated num (only one number must appear more than once): it is the answer
                if(nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        return 0;
    }
};