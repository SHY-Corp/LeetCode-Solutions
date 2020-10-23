/*
* Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
* Example 1:
* Input: [5,7]
* Output: 4
* 
*/
	 
class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while(m != n) {
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m << count;
    }
}

/* Explanation/Thought:
* Input: [10,14] 
* Bit representation of each numbers in input array is:
* 10 = 1010
* 11 = 1011
* 12 = 1100
* 13 = 1101
* 14 = 1111
* -------------
* ans= 1000 = 8
* --------------
* We can surely predict about the set bits in our answer. ith bit of Answer will be set
* if and only if ith bit of all numbers in input is set. Even if one of the number has 
* '0' as ith bit then the Answer will also have ith bit as '0'.
* 
* In above example we can prove this property, Only the 3rd bit of answer is set 
* because all numbers 10,11,12,13,14 have 3rd bit set.
* 
* Code: So we can shift bits right till the first and last number become equal.
* And for each shift we will increase our zero_count variable by 1. In above example 
* zero_count = 3. And our answer will be 2^3 or (1<<3).
*/