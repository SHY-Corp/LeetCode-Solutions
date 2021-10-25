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