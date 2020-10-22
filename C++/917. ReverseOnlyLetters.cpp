/*
Problem 917 - Reverse Only Letters
Given a string S, return the "reversed" string where all characters that are not
a letter stay in the same place, and all letters reverse their positions.

Example 1:
Input: "ab-cd"
Output: "dc-ba"

Example 2:
Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:
Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
*/

class Solution {
public:
    // auxiliary method to check if a given char is a letter
    bool checkLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    string reverseOnlyLetters(string S) {
        // string that contains the answer
        string result = S;

        // initialize i with index of the first char
        int i = 0;

        // initialize j with index of the last char
        int j = result.size() - 1;

        // continue until i is equal or greater than j
        while(i < j) {
            // increase i until it is equal a letter
            while(i < j && !checkLetter(result[i])) {
                i++;
            }

            // decrease j until it is equal a letter
            while(i < j && !checkLetter(result[j])) {
                j--;
            }

            // swap letters result[i] and result[j]
            if(i < j) {
                char tmp = result[i];
                result[i] = result[j];
                result[j] = tmp;
            }
            i++;
            j--;
        }
        // return the updated string
        return result;
    }
};