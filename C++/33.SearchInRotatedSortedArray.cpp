class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right = nums.size()-1;
        int mid;

        while(left<=right)
        {
            mid = (left+right)/2;

            if(nums[mid]==target)
                return mid;

            //if the LEFT side of the array is sorted after rotation
            if(nums[left]<=nums[mid])
            {
                //if target lies between nums[left] and nums[mid], i.e., in the sorted part of the array, update
                //right, else, update left
                if(nums[left]<=target && target<=nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            //if the RIGHT side of the array is sorted after rotation
            else
            {
                //if the target lies between nums[mid] and nums[right], in the sorted space, update left, else,
                //update right
                if(nums[mid]<=target && target<=nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};

/*
    TC: O(logn), for sorting
    SC: O(1)
*/
