/* Program name :- Reverse_Integer.cpp
 Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321
*/


class Solution {
public:
     static int reverse(int x) {
            long ret = 0;
            while (x) {
                    ret = ret * 10 + (x % 10);
                    x /= 10;      
            }
            if(ret>INT_MAX || ret<INT_MIN)
                 ret=0;
      
            return (int)ret;   
        }

};
