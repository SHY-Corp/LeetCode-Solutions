/*To implement pow(x, n), which calculates x raised to the power n (i.e. xn).
 

For example:

Input: x = 2.00000, n = 10
Output: 1024.00000*/

class Solution {
public:
    
    double myPow(double x, int n)
    {
        double c=n;
        return pow(x,c);  // using pow function to get x^n
    }
};
