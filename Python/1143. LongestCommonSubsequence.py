'''
    LeetCode Link: https://leetcode.com/problems/longest-common-subsequence/

    Given two strings text1 and text2, return the length of their longest common subsequence.

    A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

    If there is no common subsequence, return 0.

    Example:

        Input: text1 = "abcde", text2 = "ace" 
        Output: 3  
        Explanation: The longest common subsequence is "ace" and its length is 3.


    Constraints:

        1 <= text1.length <= 1000
        1 <= text2.length <= 1000
        The input strings consist of lowercase English characters only.

    Solution: 
        
        Step 1: Declare a dp array with two states, indices of letters of first string and indices of letters of second string
        Step 2: Initiate the dp array with 0, dp[i][j] stores the length of LCS for i letters of first and j letters of second
        Step 3: Start nested for loops for i and j
        Step 4: If letters at index i and j match then dp[i][j] = dp[i-1][j-1]+1
        Step 5: Else dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        Step 6: Return dp[m][n] 

    Time Complexity: O(n*m)
    Space Complexity: O(n*m)

'''

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int: 
        m = len(text1)
        n = len(text2)
        dp = [[0]*(n+1) for i in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                if text1[i-1]==text2[j-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                else:
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        return dp[m][n]