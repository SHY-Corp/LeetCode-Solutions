
// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        int maxProd=INT_MIN;
        
        int maxSoFar=1,minSoFar=1;
        
        for(int i=0;i<nums.size();i++)
        {
             int newMaxSoFar=max({maxSoFar*nums[i],nums[i],minSoFar*nums[i]});
             int newMinSoFar=min({minSoFar*nums[i],nums[i],maxSoFar*nums[i]});
            
             maxProd=max(newMaxSoFar,maxProd);
            
             maxSoFar=newMaxSoFar;
             minSoFar=newMinSoFar;
        }
        
        
        return maxProd;
    }
};