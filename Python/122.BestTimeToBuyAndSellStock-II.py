# 122. Best Time To Buy And Sell Stock II
# Language- Python 3.8.5 64-bit
# Author- @PrithirajN

#Dynamic Programming Approach

class Sol(object):
    def maxProfit(self, prices):
        profit = 0
        for i in range(len(prices) - 1):
            profit += max(0, prices[i + 1] - prices[i])
        return profit