
/**
 * Given a positive Number N, how many ways can we write it as a sum of consecutive positive integers?
 * Example:
 *      Input: 5
 *      Output = 2
 *      Explanation: 5 = 5 = 2 + 3
 *
 * Example:
 *      Input: 15
 *      Output = 4
 *      Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
 *
 * To solve this, this is the idea:
 * - For an odd number k, if there are k consecutive numbers that add up to our positive number N, then k must 
 *   divide N without any remainder.
 * - For an even number k, if there are k consecutive numbers that add up to our positive number N, then k must
 *   divide N with an .5 remainder.
 *   
 * Let's take 15,
 *  - 1, 1 is odd and divides 15 perfectly, therefore there is one consecutive number that sums up to 15 (15)
 *  - 2, 2 is even and divides 15 to 7.5, a .5 remainder, therefore there are two consecutive numbers that 
 *    sums up to 15 (7, 8)
 *  - 3, 3 is odd and divides 15 to 5.0, a perfect division, therefore there are three consecutive numbers that 
 *    sums up to 15 (4, 5, 6)
 *  - 4, 3 is even and divides 15 to 3.75, a not-so-perfect division. Therefore, there are no four consecutive
 *    numbers that sums up to 15.
 *  - 5, 5 is odd and divides 15 to 3.0, a perfect division. Therefore, there are five consecutive numbers that
 *    sums up to 15 (1, 2, 3, 4, 5).
 *  - and so on....
 *  
 *  The loop is broken when there is no chance fo a solution. For example, where negative numbers start 
 *  joining the consecutive numbers.
 *    
 */
public class Solution {

    public static int consecutiveNumbersSum(int N) {
        int answer = 0;
        Double div, num = (double) N, currentDivisor = 1.0, maxDivisor = Math.ceil(num / 2);
        while (currentDivisor.intValue() <= maxDivisor) {
            div = N / currentDivisor;
            if ((currentDivisor%2) == 0 ) {
                if (isEqualToPointFive(div)) answer++;
            } else {
                if (isEqualToZero(div)) answer++;
            }
            if (div - currentDivisor / 2 <= 1.0) break;
            currentDivisor += 1.0;
        }
        return answer;
    }

    private static boolean isEqualToPointFive(Double num) {
        Double decimal = num - num.intValue();
        return decimal == 0.5;
    }

    private static boolean isEqualToZero(Double num) {
        Double decimal = num - num.intValue();
        return decimal == 0.0;
    }
}
