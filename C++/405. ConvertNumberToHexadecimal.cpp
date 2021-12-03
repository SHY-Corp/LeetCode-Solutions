//@brief link to the question [https://leetcode.com/problems/convert-a-number-to-hexadecimal/]
//Problem 405 - Convert a number to hexadecimal

// Given an integer, write an algorithm to convert it to hexadecimal. 
// For negative integer, two’s complement method is used.

/*
    All letters in hexadecimal (a-f) must be in lowercase.
    The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
    The given number is guaranteed to fit within the range of a 32-bit signed integer.
    You must not use any method provided by the library which converts/formats the number to hex directly.
*/

//Example
/*
Input:
26

Output:
"1a"

Input:
-1

Output:
"ffffffff"
*/

/*
Explanation:
    We first declare a mapping of an integer to its equivalent hex character in a character vector hex
    If input num is 0, simply return "0"
    Now, store the input num into an unsigned integer n, this would convert a negative value to its two's complement
    Next, run a while loop until n > 0
    Append the character corresponding to n % 16 to the result string and then divide n by 16
    Return the result
*/


//First Approach 

/*
class Solution {
public:
    vector<char> hex = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    string toHex(int num) {
        if (num == 0)
            return "0";
        unsigned int n = num;
        string result = "";
        while (n > 0) {
            result = hex[n % 16] + result;
            n /= 16;
        }
        return result;
    }
};
*/


//Second Approach 


class Solution
{
public:
    string toHex(int num)
    {
        unsigned int number = num; // to manage all the negative numbers

        string ans = ""; // to store the answer

        if (number == 0)
        {
            ans = "0";
        }

        // we could not create until its not required in our program
        // like we have created const hexadecimal string in else for saving memory

        else
        {
            const string hexadecimal = "0123456789abcdef"; // to store hexadecimal numbers

            while (number > 0) // to get the hexadecimal subsiquent of decimal number
            {
                int temp = number % 16;
                ans += hexadecimal[temp];
                number /= 16;
            }
        }

        return {ans.rbegin(), ans.rend()}; // to return the iterator of string with reverse traversing
    }
};