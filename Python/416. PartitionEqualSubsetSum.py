'''
    LeetCode Link: https://leetcode.com/problems/copy-list-with-random-pointer/

    Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
    
    Example:

        Input: nums = [1,5,11,5]
        Output: true
        Explanation: The array can be partitioned as [1, 5, 5] and [11].

    Constraints:

        1 <= nums.length <= 200
        1 <= nums[i] <= 100

    Solution: 
        
        Step 1: Find total sum, if odd return False
        Step 2: Else, we need to find a subset with sum as target = total_sum/2
        Step 3: Using dynamic programming for subset sum problem
        Step 4: Initialise the dp array with two states(2D), number of elements being considered (i) and the target sum (j)
        Step 5: If some value is less than the considered target, then we have two choices either to consider or not
        Step 6: It implies dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]]
        Step 6: Else element is not considered, dp[i][j] = dp[i-1][j]
        Step 7: Return dp[len(nums)][target]

    Time Complexity: O(n*sum(nums)/2)
    Space Complexity: O(n*sum(nums)/2)

'''

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        
        total = sum(nums)
        if total%2==1:
            return False
        
        n = len(nums)
        target = total//2
        dp = [[False]*(target+1) for i in range(n+1)]
        
        
        for i in range(0, n+1):
            dp[i][0] = True

        for i in range(1, n+1):
            for j in range(1, target+1):
                if nums[i-1]<=j:
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[n][target]