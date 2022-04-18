class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int l = 0;
        int r = nums.size()-1;
        int mid;

        //iterating over the entire array using binary search method
        while(l<r)
        {
            mid = (l+r)/2;
            //if the current mid value is less than the next value, update l, else update r with current mid
            //the idea is to move towards the maximum value in the array which will also be the peak value
            if(nums[mid] < nums[mid+1])
                l = mid + 1;
            else
                r = mid;
        }
        //the last value of l will be the index of the largest value in the array
        return l;
    }
};

/*
   TC: O(log n), n = size of input array & we are reducing the search space in half after each iteration
   SC: O(1)
*/
