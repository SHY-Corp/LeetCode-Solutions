/*
 * Implement int sqrt(int x) for the given number x using binary search
 *
 * Example 1:
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
 * Example 2:
 * Input: 4
 * Output: 2
 */

class Solution {
public:
    int mySqrt(int x) {


    long long low = 1,high = x,mid;   // we are assigning the variables low , high and mid

         while(low <= high){

             mid = low + (high-low)/2;   // trying to find the square root if the given number using binary search
              long long ans = mid*mid;

             if(ans == x)              // if the mid * mid is equal to the given number  then we found the number
                 return mid;
             else if(ans > x)
                 high = mid-1;       // if number of higher then we will search in  first half of array
            else if(ans < x)
                low = mid+1;        // if number is lower then we will search in  second half of array
         }

        return min(low,high);    // we will return the minimum of both of them
    }
};
