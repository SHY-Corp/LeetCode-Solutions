class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);

        //count variable for keeping a count of every arithmetic subarray
        int count = 0;

        //if the size of array is less than 3, it won't be arithmetic!
        if(n<=2)
            return 0;

        //traversing the array from 3rd index
        for(int i=2; i<n; i++)
        {
            // for current element check difference with previous elements
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2])
            {
                //increasing by 1 if the difference is same so we can include that element in our dp array
                dp[i] = dp[i-1] + 1;
            }
            else
            {
                //this condition is also taking into account that if an array is arithmetic but the elements are present such that
                //the differences are not equal, so we assign it 0, e.g = [1,2,3,4,6,8], the condition will not hold for [3,4,6].
                dp[i] = 0;
            }

            //increasing the count by summing these combinations at each step
            count+=dp[i];
        }
       return count;
    }
};

/*
Dry run for an example:

[1, 3, 5, 7, 9] :-                               dp [0, 0], dp[i]=0+0=0, count=0 + dp[i]
a.) [1,3,5]: 3-1=5-3=2, combinations till 5 = 1, dp [0, 0, 1], dp[i]=1, count=0+1=1
b.) [3,5,7]: 5-3=7-5=2, combinations till 7 = 2, dp [0, 0, 1, 2], dp[i]=2, count=1+2= 3
c.) [5,7,9]: 7-5=9-7=2, combinations till 9 = 3, dp [0, 0, 1, 2, 3], dp[i]=3, count=3+3=6

Therefore, there are 6 arithmetic subarrays: [1,3,5], [3,5,7], [5,7,9], [1,3,5,7],[3,5,7,9],
[1,3,5,7,9]
*/
