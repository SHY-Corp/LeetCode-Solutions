// problem - 858. Mirror Reflection

/*
    There is a special square room with mirrors on each of the four walls.  
    Except for the southwest corner, there are receptors on each of the remaining corners, 
    numbered 0, 1, and 2.

    The square room has walls of length p, and a laser ray from the 
    southwest corner first meets the east wall at a distance q from the 0th receptor.

    Return the number of the receptor that the ray meets first.  
    (It is guaranteed that the ray will meet a receptor eventually.)
*/

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int n = 1, m = 1;
        
        /*
         * if n == even then mirror 2
         * else 
         *   if m is odd then mirror 1
         *   else mirror 0
        **/
        while(m * p != n * q) {
            n++;
            m = (n * q) / p;
        }
        
        if(n & 1) {
            if(m & 1) return 1;
            else return 0;
        } else return 2;
    }
};

// Time Complexity = O(n) [where n is ((m*p)/q)]
// Space Complexity = O(1)