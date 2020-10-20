// Problem - 1. Two Sum

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        for(int i=0; i<nums.size()-1; i++) {            //outer loop  0 --> size of vector nums -1
            
            for(int j=i+1; j<nums.size(); j++) {        //inner loop  i+1 --> size of vector nums
                
                if(nums[i]+nums[j]==target && i!=j)   
                    return vector<int> {i,j};         // return vector of i and j if condition satisfies
                    
            }
        }
        return {};   // return empty vector if condition fails for every element
    }
};
