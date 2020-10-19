//300. Longest Increasing Subsequence
//Given an unsorted array of integers, find the length of longest increasing subsequence.

/*Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
*/

/* Approach: We can solve this problem using dynamic programming.
We make use of a dp array to store the required data. dp[i] represents the length
of the longest increasing subsequence possible considering the array elements upto the ith
  index only ,by necessarily including the ith element.
    If you got number greater than last number in dp.
    just push that number in dp.
    Otherwise find the next greater number in dp for this number.
    and replace with that.
    Because whatever you will get with just larger number 
    surely will get with that just smaller number.
      example: [10,9,3,5,6,4]
      dp: [10]->[9]->[3]->[3,5]->[3,5,6]->[3,4,6]
 */
 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
          return 0;
        vector<int>dp;
        dp.push_back(nums[0]);

        for(int i = 1;i<n;i++)
        {
            if(nums[i] <= dp[dp.size() - 1])
            {
                dp[upper_bound(dp.begin(), dp.end(), nums[i] - 1) - dp.begin()] = nums[i];
            }
            else
            {
                dp.push_back(nums[i]);
            }
        }
        return dp.size();
    }
};