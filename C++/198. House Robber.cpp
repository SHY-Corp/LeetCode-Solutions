/*To determine the maximum amount of money that can robbed tonight without alerting the police.

 

For Example :

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/

class Solution {
public:
    int rob(vector<int>& hval) {
       int n = hval.size();
        if (n == 0) 
        return 0; 
    if (n == 1) 
        return hval[0]; 
    if (n == 2) 
        return max(hval[0], hval[1]); 
  
    // dp[i] represent the maximum value stolen 
    // so far after reaching house i. 
    int dp[n]; 
  
    // Initialize the dp[0] and dp[1] 
    dp[0] = hval[0]; 
    dp[1] = max(hval[0], hval[1]); 
  
    // Fill remaining positions 
    for (int i = 2; i<n; i++) 
        dp[i] = max(hval[i]+dp[i-2], dp[i-1]); 
  
    return dp[n-1]; 
        
   
    }
};
