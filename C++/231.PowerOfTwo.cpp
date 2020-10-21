class Solution {
public:
    bool isPowerOfTwo(int n) {
        // (n>0) means that the number is not zero 
        // a number which is power of two has one set bit so !x&(x-1) return 1 if the number is power of two
        return (n>0)&&(n&&!(n&(n-1)));
        // 8- 1000
        // 7- 0111
        //&  !0000 = 1111 so 8 is power of two
    }
};
