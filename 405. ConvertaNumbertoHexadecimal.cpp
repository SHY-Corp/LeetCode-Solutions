/**
 * @file 405. ConvertaNumbertoHexadecimal.cpp
 * @author Vipul Kumar Singh
 * @brief link to the question [https://leetcode.com/problems/convert-a-number-to-hexadecimal/]
 * @version 0.1
 * @date 2021-12-01
 *
 * @copyright Copyright (c) 2021
 *
 */

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