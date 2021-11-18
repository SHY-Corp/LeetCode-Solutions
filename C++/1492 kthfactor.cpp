/**
 * @file 1492 kthfactor.cpp
 * @author Vipul Kumar Singh
 * @brief
 * @version 0.1
 * @date 2021-11-17
 * @copyright Copyright (c) 2021
 */

/*
Given two positive integers n and k.

A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

 */

/*

Example 1:

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.

*/

/*
Example 2:

Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.
*/

/*
Example 3:

Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.
*/

/*
Example 4:

Input: n = 1, k = 1
Output: 1
Explanation: Factors list is [1], the 1st factor is 1.
*/

/*
Example 5:

Input: n = 1000, k = 3
Output: 4
Explanation: Factors list is [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000]. 

Constraints:

1 <= k <= n <= 1000
*/


class Solution
{
public:
    int kthFactor(int n, int k)
    {

        int temp = -1; // to store return the value for the unexpected output
        
        // k denotes to the index in vector arr 
        
        if (k > n)
        // if the index is greater than the number n 
        // for example 4 then the factor of 4 is [ 1 , 2 , 4 ]
        // then k must be less than or equal to 3 as its index value
            return temp;

        else
        {
            int i = 2;
            vector<int> arr;
            arr.push_back(1); // as 1 is factor of all the number's i.e  its always in arr 

            while (i <= n) // if i is less than n 
            {
                if (n % i == 0) // if n is divisible by i then put then the i in arr vector
                {
                    arr.push_back(i);
                }

                i++; // increment
            }
            
            if (k > arr.size())
                return temp;

           else
               return arr[k-1];
        }
    }
};