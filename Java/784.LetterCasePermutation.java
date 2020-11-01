// LeetCode 784: Letter Case Permutation
// https://leetcode.com/problems/letter-case-permutation/

/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

Example 1:
Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: S = "3z4"
Output: ["3z4","3Z4"]

Example 3:
Input: S = "12345"
Output: ["12345"]

Example 4:
Input: S = "0"
Output: ["0"]
 

Constraints:
S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/

class Solution {
    public List<String> letterCasePermutation(String S) {
        // Initialize result list
        List<String> permutations = new ArrayList<String>();

        // Add S into the list since it will always be in the result
        permutations.add(S);

        // Call recursive function that will backtrack to generate all permutations
        generatePermutations(S.toCharArray(), permutations, 0);

        // Return the result list
        return permutations;
    }

    public void generatePermutations(char[] s, List<String> permutations, int index) {
        // Base case: Return out if the index is out of bounds
        if (index >= s.length) {
            return;
        }

        // If the character at the current index is a letter:
        // 1. Change its case
        // 2. Add the new string into the result list
        // 3. Call the recursive function with this new string and move onto next index
        // 4. Revert back to its original case
        if (Character.isLetter(s[index])) {
            s[index] = toggleCase(s[index]);
            permutations.add(new String(s));
            generatePermutations(s, permutations, index + 1);
            s[index] = toggleCase(s[index]);
        }

        // Call the recursive function with the original string and move onto next index
        generatePermutations(s, permutations, index + 1);
    }

    // Helper function to convert character case easily
    private char toggleCase(char c) {
        if (Character.isUpperCase(c)) {
            return Character.toLowerCase(c);
        } else {
            return Character.toUpperCase(c);
        }
    }
}