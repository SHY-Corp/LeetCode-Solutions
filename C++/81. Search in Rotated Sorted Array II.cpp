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

//Adding a better approach:

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int mid;

        while(left<=right)
        {
            mid = (left+right)/2;

            if(nums[mid] == target)
                return true;

            /*the tricky part where nums[l]=nums[right]=nums[mid], essentially when nums[left]==nums[right] and
              it's not equal to target, it's better to shrink the binary search space from both sides thereby
              decreasing the overall operation steps.
            */
            if((nums[mid]==nums[left]) && (nums[mid]==nums[right]))
            {
                left++;
                right--;
            }
            //if the LEFT side of the array is sorted after rotation
            else if(nums[left]<=nums[mid])
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
        return false;
    }
};

/*
   TC: O(n) worst case, O(logn) best case, n = no. of elements in the array.

       -Having duplicates in the array does affect the run-time complexity!
       -If there are duplicates, we are not applying binary search to some spaces as the values are the
        same and not equal to target making it our worst case - O(n), whereas
       -The complexity is O(logn) when the elements are distinct(without duplicates) because now we are able to
        divide our search space into half, and carry out the binary search accordingly.

   SC: O(1)
*/
