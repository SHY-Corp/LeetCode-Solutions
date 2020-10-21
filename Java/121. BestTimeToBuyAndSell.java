/* Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
 */

class Solution {
    public int maxProfit(int[] prices) {
        int lsf = Integer.MAX_VALUE; /* least so far */
        int pist = 0; /* Profit if sold today */
        int op = 0; /* overall profit */

        for(int i=0; i<prices.length; i++){
            if(prices[i]< lsf){
                lsf = prices[i];
            }

            pist = prices[i] - lsf;
            if(pist > op){
                op = pist;
            }
        }

        return op;
    }
}
