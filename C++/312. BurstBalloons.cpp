/*

Problem : Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely

Approach : The problem is similar to the problem of Matrix Chain multiplication which we solve using Dynamic programming
		   dp[i][j] in here means, the maximum coins we get after we burst all the balloons between i and j in the original array.

		   For example with input [3,1,5,8] :
		   dp[0][0] means we burst ballons between [0,0], which means we only burst the first balloon in original array. So dp[0][0] is 1 * 3 * 1 = 3.
		   dp[1][1] means we burst balloons between [1][1], which means we only burst the second ballon in the original array. So dp[1][1] is 3 * 1 * 5 = 15.

		   Now since for first and last elements we have to multiply by additional 1 so I inserted 1 at the start and the end of the array
		   So in the end for this problem we want to find out dp[1][ new_array.length - 1 ], here since in the loop of solve I use st - 1 so I have started with (1, len - 1) instead of (0, len - 1)
		  To get that we need the transition function : 
		  for (int k = st; k < en; ++k)
			val = max(val, solve(nums, st, k) + solve(nums, k + 1, en) + nums[st - 1] * nums[k] * nums[en])

		  This transition function basically says in order to get the maximum value we can get for bursting all the balloons between [ i , j] , we just loop through each balloon between these two indexes and make them to be the last balloon to be burst

*/

class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int>& nums, int st, int en) {
        if(st >= en) return 0;
        if(dp[st][en] != -1) return dp[st][en];
        int val = INT_MIN;
        for(int k = st; k < en; k++) {
            val = max(val, (solve(nums, st, k) + solve(nums, k + 1, en) + nums[st - 1] * nums[k] * nums[en]));
        }
        return dp[st][en] = val;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); nums.push_back(1);
        int n = nums.size();
        dp.resize(n, vector<int>(n, -1));
        int val = solve(nums, 1, n - 1);
        return val;
    }
};
