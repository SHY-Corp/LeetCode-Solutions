/**
 * @file 367. ValidPerfectSquare.cpp
 * @author Vipul kumar Singh  ((https://github.com/vipul-2003))
 * @version 0.1
 * @date 2021-11-11
 * @link https://leetcode.com/problems/valid-perfect-square/
 * @copyright Copyright (c) 2021
 */

/*
Problems-
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Follow up: Do not use any built-in library function such as sqrt.

*/

/*
Example 1:

Input: num = 16
Output: true

Example 2:

Input: num = 14
Output: false

Constraints:

1 <= num <= 2^31 - 1

*/

class Solution
{
public:
    bool isPerfectSquare(int num)
    {

        bool temp = false; // to check that the valid perfect square found or not , if yes , then now stop ... 

        if (num == 1) // edge cases
            return true;

        else if (num == 0) // edge cases
            return 0;

        else
        {
            for (long long int i = 2; i <= num / 2; i++) // for loop for traversing 
            {
                if (i * i == num) // i^2 == num (i square equal to the number "num")
                {
                    temp = true;
                    break;
                }
            }
        }

        return temp;
    }
};
