/*
Given a Given a string s, return the longest palindromic substring in s.

Example TestCase ->
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
 */

class Solution{
    public String longestPalindrome(String s) {
        int n = s.length();
        if(n == 0) return "";
        
        boolean[][] dp = new boolean[n][n];
        
        int maxSoFar = 0;
        String ans = "";
        
        for(int gap = 0;gap<n;gap++){
            int sp = 0; int ep = gap;
            while(ep<n){
                char ch1 = s.charAt(sp);
                char ch2 = s.charAt(ep);
                
                if(gap == 0){
                    dp[sp][ep] = true;
                    maxSoFar = 1; ans = ch1+"";
                }else if(gap == 1 && ch1 == ch2){
                    dp[sp][ep] = true;
                    maxSoFar = 1; ans = ""+ch1+ch1;
                }else if(ch1 == ch2 && dp[sp+1][ep-1]){
                    dp[sp][ep] = true;
                    if(ep-sp+1 > maxSoFar){
                        maxSoFar = ep-sp+1;
                        ans = s.substring(sp,ep+1);
                    }
                }
                sp++; ep++;
            }
        }
        return ans;
    }
}
