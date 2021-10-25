/*
    829. Consecutive Numbers Sum

    Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.

    We simply use the series formula to solve this question.
*/

class Solution {
   public:
    int consecutiveNumbersSum(int N) {
        // using series formula we can solve this
        // (n^2+n)/2 + nx by the definition of divides
        // if integer x exists then we know the solution is valid
        int consecutives = 0;
        int i = 1;
        while (true) {
            int d = (i * i + i) / 2;
            int f = N - d;
            if (f < 0) {
                break;
            }
            if (f % i == 0) consecutives++;
            i++;
        }
        return consecutives;
    }
};