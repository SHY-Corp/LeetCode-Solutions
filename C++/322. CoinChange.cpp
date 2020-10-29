"""
Problem Statement:
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
Sample Input:
coins = [1,2,5], amount = 11
Output : 3
Explanation : 11 = 5 + 5 + 1
"""
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        if(n==0 || n==1)
            return profit;
        int min_price=prices[0];
        for(int i=0;i<n;i++){
            min_price=min(min_price,prices[i]);
            profit=max(prices[i]-min_price,profit);
        }
        return profit;                    
    }
};
