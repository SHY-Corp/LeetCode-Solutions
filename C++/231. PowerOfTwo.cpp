//231. Power of Two

/*Given an integer n, write a function to determine if it is a power of two.

 
Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
*/



class Solution {
public:
    bool isPowerOfTwo(int n) {
         if( n <= 0)
        {
            return false;
        }
        if((n&(n-1)) == 0)
        {
            return true;
        }
        else{
            return false;
        }
    }
};