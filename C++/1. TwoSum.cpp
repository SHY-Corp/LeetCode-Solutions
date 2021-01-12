// Problem - 1. Two Sum

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        /*
        	O(n^2) Time, O(1) Space solution,
	        for(int i=0; i<nums.size(); i++) {            //outer loop  0 --> size of vector nums
	            
	            for(int j=1; j<nums.size(); j++) {        //inner loop  1 --> size of vector nums
	                
	                if(nums[i]+nums[j]==target && i!=j)   
	                    return vector<int> {i,j};         // return vector of i and j if condition satisfies
	                    
	            }
	        }
	        return {};   // return empty vector if condition fails for every element
        */
        /*
			O(nlogn) Time, O(1) Space solution (modifies the array)
			sort(nums.begin(), nums.end()); // Sort in a increasing order, bottleneck of the program
			int i = 0, j = nums.size() - 1;
			while (i < j) {
				if (nums[i] + nums[j] == target) {
					return vector<int> {i, j};
				}
				else if (nums[i] + nums[j] < target) {
					i++;
				}
				else
					j--;
			}
			return {}; // return empty vector if no solution found
        */
        
		//	O(n) Time, O(n) Space solution
		unordered_map<int, int> m; // To store index of a number found already

		for (int i = 0; i < nums.size(); i++) {
            int required_num = target - nums[i]; // complement of the number num[i]
			if (m.find(required_num) != m.end())
				return vector<int> {i, m[required_num]}; // If number and its complement is found, return it
			else
				m[nums[i]] = i; // Add the number to the unordered_map m
		}
		return {}; // return empty vector if no solution found
    }
};