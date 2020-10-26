/*
We use dynamic programming solution!

We know that every number is represented as a binary number on the computer.
Now imagine that we are going to break a number into a part already known and another part that is easy to know.
If we divide a number by 2, we just remove the least significant bit, however this new number has already been calculated
and we are able to generate the answer for the current number in O (1).
It is only necessary to check if the least significant bit is 1 or 0 and use the answer of the number divided by 2.
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        dp[0] = 0;
        
        for(int i = 1; i <= num; i++){
            dp[i] = dp[i >> 1] + (i & 1);
        }
        
        return dp;
    }
};
