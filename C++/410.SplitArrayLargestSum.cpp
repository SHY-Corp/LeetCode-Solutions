class Solution {
public:
    bool helper(vector<int>& nums, int mid, int m)
    {
        int subArrayCount = 1;
        int sum=0;

        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];

            //if the current element being added makes the sum more than mid, increment the subArrayCount &
            //reset the value of sum to the current element in the array from which new addition iteration
            //for another sub-array sum begins
            if(sum>mid)
            {
                subArrayCount++;
                sum = nums[i];
            }
        }
        //if subArrayCount is <=m, then we can split the array and try moving towards smaller values
        return subArrayCount <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        int maxElement = 0;

        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            maxElement = max(maxElement, nums[i]);
        }

        if(m==nums.size())
            return maxElement;

        //applying binary search using the lowest sum and the sum of all the elements in an array
        int left = maxElement;
        int right = sum;
        int mid;
        int finalSum = 0;

        while(left<=right)
        {
            mid = (left+right)/2;

            //check if we need less/more sub-arrays from m if we want the largest sub-array's sum to be <= mid
            if(helper(nums, mid, m)==true)
            {
               //if less splits required than m, update the finalSum & move towards smaller values(i.e., left)
                finalSum = mid;
                right = mid - 1;
            }
            else
            {
                //if more splits required than m, move towards the larger values(i.e., right)
                left = mid + 1;
            }
        }

        return finalSum;
    }
};

/*
   TC: O(NlogS), logS=total iterations in Binary Search, and
                 O(n) for the no. of times recursive helper function is called
   SC: O(1)
*/
