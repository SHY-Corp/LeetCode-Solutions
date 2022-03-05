/*
   This problem is similar to 198. House Robber problem. I would suggest you solve that first
   and then try this one. I originally solved it using 2 arrays and then optimized it by only keeping
   track of previous 2 values instead of maintaining one full array.
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        //maintaining a vector of points sized 10001(look at the constraints)
        vector<int> points(10001);

        //map elements to the amount of points that we can gain from taking each element
        for(int i: nums)
        {
            points[i] += i;
        }

        //base cases for previous 2 values from the current value as we are only keeping a check on 2
        //values instead of populating a whole new array
        int twoBack = 0;  //previous 2 values
        int oneBack = 0;  //previous value

        int temp;

        for(int earn: points)     //val = points[i]
        {
            //when we get to the next number, one step back will become two steps back, and the current
            //step will become the previous step
            temp = oneBack;
            oneBack = max(oneBack, twoBack + earn);
            twoBack = temp;
        }
        return oneBack;

       /* int n = 10001;
        vector<int> points(n, 0), dp(n, 0);

        for(int i=0; i<nums.size(); i++)
        {
            points[nums[i]] += nums[i];
        }
        dp[0] = 0;
        dp[1] = points[1];
        for(int i=2; i<n; i++)
        {
            dp[i] = max(dp[i-2] + points[i], dp[i-1]);
        }

        return dp[n-1];*/
    }
};
