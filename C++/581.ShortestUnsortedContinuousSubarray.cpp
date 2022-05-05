class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        //maintaining 2 pointers
        int start = 0;
        int end = n-1;

        //finding the 1st value from the start before which all the numbers are small
        //this is also the point AFTER which a number might still be small
        while(start+1 <= n-1 && nums[start]<=nums[start+1])
            start++;

        //this implies that the array is already sorted
        if(start==end)
            return 0;

        //finding the 1st value from the end after which all the numbers are big
        //once again, this is also a point BEFORE which a number might be big
        while(end-1>=0 && nums[end]>=nums[end-1])
            end--;

        //try test case: [1,3,2,2,2] to understand the further step
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        //traversing between the current start & end pointers to find the min and max values in-between
        for(int i=start; i<=end; i++)
        {
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }

        //updating the value of start once again, now that we know where our minimum value is
        while(start-1>=0 && nums[start-1]>minVal)
            start--;

        //updating the value of end wrt the maximum value
        while(end+1<n && nums[end+1]<maxVal)
            end++;

        //end-start+1 will now give us the length of shortest subarray
        return end-start+1;
    }
};

/*
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
