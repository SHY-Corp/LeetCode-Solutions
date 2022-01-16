//Checkout the comments in the end to fully understand the bit manipulation approach!

class Solution {
public:
    bool isPowerOfFour(int n) {
        /*
        int i;
        i = n;             //scope issues, therefore assigning n to i.

        if(n==0)
            return false;

        while(i!=1)
        {
            if(i%4 != 0)
                return false;
            i = i/4;
        }
        return true;
        */

        //in order to solve without loops/recursion, applying the bit manipulation approach
        if(n<1)
            return false;

        int count = 0;
        if(n && !(n & (n-1)))    //for checking if only 1 bit
        {
            while(n>1)     //for counting 0 bits after the set 1 bit
            {
                n=n>>1;
                count++;
            }
            if(count%2==0)
                return true;
        }
        return false;      //also, if more than  1 bit set, then it is not a power of 4. Same for 2
    }
};

/*
Pattern for powers of 4:

4    = 100
16   = 10000
64   = 1000000
256  = 100000000
1024 = 10000000000

So, powers of 4 have ONE bit, followed by EVEN no of zeroes. Also, the number is increasing with each
power. Thus, if we have 1 set bit followed by even count of 0's, I'm returning true, otherwise false.

The final false statement is if there are more than 1 set bit, then it won't be a power of 2!
*/
