/*
693. Binary Number with Alternating Bits

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101

Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.

*/

class Solution {
public:
    bool hasAlternatingBits(int n) {        
        
        int last = n%2;
        n=n>>1;
        
        while(n>0) {
            int current = n%2;
            if(current == last) {
                return false;
            }
            
            last = current;
            n=n>>1;
        }
        return true;
    }
    
};
