class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int count=0;

        while(n>0)
        {
            //1 is the number where only the last bit is 1,(x&1)=1 if the last bit of x is 1 and 0 otherwise
            if(n&1 == 1)
                count++;

            // shift bits to remove lower bit
            n = n >> 1;
        return count;
    }
};
