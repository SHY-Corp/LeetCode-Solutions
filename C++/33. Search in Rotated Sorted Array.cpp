// You are given an integer array nums sorted in ascending order, and an integer target.
// Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// If target is found in the array return its index, otherwise, return -1.




class Solution {
public:
    int binary_search(vector<int>& nums, int target, int start, int end){
        while(start<=end){
            int middle=start+(end-start)/2;
            if(nums[middle]==target)
                return middle;
            else if(nums[middle]<nums[end]){
                if(target>nums[middle] && target<=nums[end])
                    start=middle+1;
                else
                    end=middle-1;
            }
            else{
                if(target>=nums[start] && target<nums[middle])
                    end=middle-1;
                else
                    start=middle+1;
            }
            // else if(nums[middle]>target && nums[end]>target)
            //     start=middle+1;
            // else
        }
        return -1;
    }
     int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binary_search(nums, target, 0, n-1);
        
    }
};