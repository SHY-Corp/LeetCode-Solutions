# Wildcard Matching.

''' 
Python program to implement Wildcard Matching Algorithm.
' s ' is the input string and ' p ' is the Wildcard pattern.

Function matches input string 's' with the given pattern 'p',
and return True if matches otherwise False.
'''
# Dynamic Programming Approach.

class Solution(object):
    def isMatch(self,s ,p) -> bool:
        s_len = len(s)
        p_len = len(p)
        
        if (p_len == 0):
            return (s_len == 0) # For empty pattern
       
        dp = [[False for i in range(p_len + 1)] for j in range(s_len + 1)] # DP matrix for storing results of subproblems
        dp[0][0] = True
        
        for i in range(1,p_len + 1):
            if p[i - 1] == '*':
                dp[0][i] = dp[0][i-1]
            
        for i in range(1, s_len + 1):
            for j in range(1, p_len + 1):
                if s[i - 1] == p[j - 1] or p[j - 1] == '?':
                    dp[i][j] = dp[i-1][j-1]
                
                elif p[j - 1] == '*':
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                
                else :
                     dp[i][j] = False
       
        return dp[s_len][p_len]
    
'''
s = input('string -> ')
p = input('pattern -> ')

wildcard_match  = Solution()

print(wildcard_match.isMatch(s,p))
'''