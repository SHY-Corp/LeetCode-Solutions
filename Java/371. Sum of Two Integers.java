/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
*/

class Solution {
    public int getSum(int a, int b) {
        return b==0 ? a : getSum((a^b), (a&b) << 1);
    }
}

/* Explanation:
Below addition properties(at bit level) are being used in the solution.
0 + 0 = 0
0 + 1 = 1
1 + 0 = 0. These 3 are being done by (a ^ b).
1 + 1 = 0 (carry 1). This is being done here using ((a & b) << 1).


The solution tries to replicate this above behaviour by doing manipulation using XOR and AND opeartions. Try taking few simple examples (try doing 2 + 3) to understand the working of solution.

*/