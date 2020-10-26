/*
We have a collection of rocks, each rock has a positive integer weight.
Each turn, we choose any two rocks and smash them together. weight of arger stone decreases by weight of smaller stone.
find smalles possible weight of last remaining stone

Problem link- https://leetcode.com/problems/last-stone-weight-ii/

Approach-
Similar to dividing stones into two groups having minimum difference and then return that difference. 0-1 Knapsack approch can also be used
*/

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        vector<bool> dp(1501, false); //size = (max len) * (mx wt)/2. Stores if wt i is possible or not
        dp[0] = true;
        for (int s : stones) // for each stone
        {
            sum += s; // maintain sum of stones 0..current index
            for (int i = min(1500, sum); i >= s; i--)
            {                              //from sum to s
                dp[i] = dp[i] | dp[i - s]; // if i-s is true=> make i as true
            }
        }
        for (int i = sum / 2; i >= 0; i--)
        {
            if (dp[i])
            {
                return sum - i - i; //return min diff i.e max possible i closer to sum/2
            }
        }
        return 0;
    }
};
