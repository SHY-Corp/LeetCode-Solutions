/* 
Say you have an array prices for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
*/

class Solution {
    public int maxProfit(int[] prices) {
        int bd = 0; // buy date
        int sd = 0; // Sell date

        int profit = 0;

        for(int i=1; i<prices.length; i++){
            if(prices[i] > prices[i-1]){
                sd++;
            }else{
                profit += prices[sd] - prices[bd];
                bd = sd =i;
            }
        }
        profit += prices[sd] - prices[bd];
        return profit;
    }
}
