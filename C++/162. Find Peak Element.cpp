// problem - 162. Find Peak Element

/*
    A peak element is an element that is greater than its neighbors.
    Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
    The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
    You may imagine that nums[-1] = nums[n] = -∞.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), answer=0;

        // to handle edge case
        if(n < 2) return 0; 
        if(n == 2) {
            if(nums[0] > nums[1]) return 0;
            else return 1;
        }
        
        // to find the index of the peak
        for(int i=1; i<n-1; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                answer = i;
                break;
            }
        }
        
        // to check whether the last element is the peak 
        if(nums[n-1] > nums[n-2]) {
            return n-1;
        }
        
        return answer;
    }
};

// Time Complexity - O(n) Linear Time
// Space Complexity - O(1) Constant Time