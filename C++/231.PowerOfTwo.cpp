class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0)&&(n&&!(n&(n-1)));

    }
};
