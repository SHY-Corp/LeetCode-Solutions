class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        //maintaining relevant pointers for binary search
        int left = 0;
        int right = n-1;
        int mid;

        //edge case
        if(n==1)
            return nums[0];

        while(left<right)
        {
            mid = left + (right-left)/2;

            //if right side was rotated, expecting min. value between [mid+1, right]
            if(nums[mid] > nums[right])
                left = mid+1;
            //either left side was rotated or is sequential, implying that the min. value can be found between [left, mid]
            else
                right = mid;
        }
        //the value at nums[left] will have the min. value
        return nums[left];
    }
};

//TC: O(logn), for binary search
//SC: O(1), for constant space
