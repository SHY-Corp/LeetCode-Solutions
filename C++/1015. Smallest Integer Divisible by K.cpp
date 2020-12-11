// problem - 1015. Smallest Integer Divisible by K

/*
    Given a positive integer K, you need to find the length of the smallest positive integer N 
    such that N is divisible by K, and N only contains the digit 1.

    Return the length of N. If there is no such N, return -1.

    Note: N may not fit in a 64-bit signed integer.
*/

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        // if either k is even(divisible by 2) or divisible by 5 
        if(!(K&1) || !(K%5)) return -1;
        
        int rem = 0;
        for(int i=1; i<=K; i++) {
            rem = (rem * 10 + 1) % K;
            
            if(rem == 0) return i;
        }
        
        return -1;
    }
};

// Time Complexity = O(K)
// Space Complexity = O(1)