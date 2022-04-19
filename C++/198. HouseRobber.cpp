/*198. House Robber

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint stopping
you from robbing each of them is that adjacent houses have security system
connected and it will automatically contact the police if two adjacent houses
were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each
house, determine the maximum amount of money you can rob tonight without
alerting the police.

For Example :

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/

//optimized dynamic programming approach
//TC: O(n), SC: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        //if there is only 1 house, the max amount that can be robbed = value of that house
        if(n==1)
            return nums[0];

        //maintaining 3 variables which store the 1st index, maximum of 1st 2 indices and the current value
        //which will get updated with the previous value
        int prev2Val = nums[0];
        int prev1Val = max(nums[0], nums[1]);
        int currVal = prev1Val;

        //iterating from the 3rd house till n houses
        for(int i=2; i<n; i++)
        {
            //udating current value with the max value from choosing house i or NOT choosing it
            currVal = max(prev2Val+nums[i], prev1Val);
            //updating subsequent previous 2 and previous 1 value
            prev2Val = prev1Val;
            prev1Val = currVal;
        }
        return currVal;
    }
};

/*
// Recursive approach with memoization
class Solution {
public:

    int house(vector<int>& nums, int i, vector<int>& dp)
    {
        if(i>=nums.size())
            return 0;
        else
        {
            if(dp[i]!=-1)
                return dp[i];
            else
                dp[i] = max((nums[i] + house(nums, i+2, dp)), house(nums, i+1, dp));
        }
      return dp[i];
    }

    int rob(vector<int>& nums) {

        vector<int> dp(nums.size()+1, -1);
        return house(nums, 0, dp);
    }
};

//TC: O(n), SC: O(n)
*/


