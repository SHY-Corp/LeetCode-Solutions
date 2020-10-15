/**
 * Question:
 * Given a string, your task is to count how many palindromic substrings in this string.
 * <p>
 * The substrings with different start indexes or end indexes are counted as different substrings even they consist of
 * same characters.
 * <p>
 * Example 1:
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * <p>
 * Example 2:
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * <p>
 * Constraints:
 * The input string length won't exceed 1000.
 */
class Solution {
    public int countSubstrings(String s) {
        int stringLength = s.length();
        int count = 0;
        boolean[][] isPalindrome = new boolean[stringLength][stringLength];

        // Resetting matrix
        for (int i = 0; i < stringLength; ++i) {
            for (int j = 0; j < stringLength; ++j) {
                isPalindrome[i][j] = false;
            }
        }

        // String length 1
        for (int i = 0; i < stringLength; ++i) {
            ++count;
            isPalindrome[i][i] = true;
        }

        int end = (stringLength - 1);

        // String length 2
        for (int i = 0; i < end; ++i) {
            String currentSubstring = s.substring(i, (i + 2));
            if (currentSubstring.charAt(0) == currentSubstring.charAt(1)) {
                ++count;
                isPalindrome[i][i + 1] = true;
            }
        }

        // String length more than 3
        for (int i = 2; i <= end; ++i) {
            for (int j = 0; j < (i - 1); ++j) {
                if (s.charAt(j) == s.charAt(i) && isPalindrome[j + 1][i - 1]) {
                    ++count;
                    isPalindrome[j][i] = true;
                }
            }
        }

        return count;
    }
}
