/**
 * Question:
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * <p>
 * Example:
 * Input: "bbbab"
 * Output: 4
 * One possible longest palindromic subsequence is "bbbb".
 * <p>
 * Example:
 * Input: "cbbd"
 * Output: 2
 * One possible longest palindromic subsequence is "bb".
 * <p>
 * Constraints:
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 */

class Solution {
    public int longestPalindromeSubseq(String s) {
        // Reverse of the string
        String reverseOfString = new StringBuilder(s).reverse().toString();
        int length = s.length();
        // Cost matrix to store cost
        int[][] cost = new int[length+1][length+1];

        // Compare string with its reverse to check for the palindrome
        for(int i = 1; i <= length; i++) {
            for(int j = 1; j <= length; j++) {
                if (reverseOfString.charAt(i-1) == s.charAt(j-1)) {
                    cost[i][j] = cost[i-1][j-1] + 1;
                } else if (cost[i-1][j] >= cost[i][j-1]) {
                    cost[i][j] = cost[i-1][j];
                } else {
                    cost[i][j] = cost[i][j-1];
                }
            }
        }

        return cost[length][length];
    }
}