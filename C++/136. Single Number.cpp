class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a,n,i;

        /* I am using the bit manipulation approach here. The
        idea is, if you XOR 2 same numbers, you get a 0, and if 
        the numbers are different, you get a 1(Strictly speaking
        in terms of binary numbers- 0's and 1's).

        0^0=0, 1^1=0;
        0^1 or 1^0 = 1

        However, we have an array here, with non-binary numbers,
        but the logic still holds.
        Eg. [4,5,6,6,4]
        I should get 5 as an output.
        If I apply XOR operation on this array, this is what it 
        will look like-

        4^5^6^6^4 = (4^4)^(6^6)^5 = 0 ^ 0 ^ 5 = 0 ^ 5 = 5
        When you XOR same numbers, you get a 0, thus 4 ^ 4 = 0.
        In this case, we already know that numbers are repeating twice
        and there is only one number that's not repeating. So, by using XOR,
        we are actually eliminating the repeating numbers and using their XORed 
        value to once again XOR with the last remaining number which is not repeating,
        thus we have 0 ^ 5 = 5, i.e. a number when XORed with a different number yields
        that number.
        */
        a=0;
        n = nums.size();
        
        for(i=0; i<n; i++)
        {
            a = a^nums[i];
        }
        return a;
    }
};

