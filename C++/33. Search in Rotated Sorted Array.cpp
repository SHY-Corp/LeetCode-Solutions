/* You are given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

Sample inputs and outputs :
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4
*/




class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n==1){
            if(nums[0]==target) return 0;
            else return -1; 
        }
        
        int low = 0, high = n-1, mid = 0, prev = 0, next = 0, pivot = 0;
        //find pivot
        while(low <= high) {
            mid = low + (high-low+1)/2;
            prev = (mid-1+n)%n;
            next = (mid+1)%n;
            if(nums[mid]> nums[next]) {
                pivot = next;
                break;
            }
            else {
                if(nums[low] < nums[mid] ) {
                    low = next;
                }
                else high = prev;
            }
        }
        //divide bounds into two sub arrays both sorted
        int low1 = 0, high1 = n-1, low2 = 0, high2 = n-1;
        if(nums[pivot] == target) return pivot;
        else {
            high1 = (pivot-1+n)%n;
            low2 = (pivot+1)%n;
        }
        
        
        while(low1 <= high1) {
            mid = low1 + (high1 - low1)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) high1 = mid-1;
            else low1 = mid+1;
        }
        
        while(low2 <= high2) {
            mid = low2 + (high2 - low2)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) high2 = mid-1;
            else low2 = mid+1;
        }
        return -1;
        
        
        
    }
};
