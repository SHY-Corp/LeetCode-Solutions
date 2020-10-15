// Problem:
// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction
// (i.e., buy one and sell one share of the stock),
// design an algorithm to find the maximum profit.
// Note that you cannot sell a stock before you buy one.

// Approach:
// Initialize mn variable to first value. Now, find the running difference between current
// value and mn variable, since that would give us the required maximum profit.

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (!n) return 0;
		int mn = prices[0], ans = 0;
		for (int i = 1; i < n; i++)
		{
			ans = max({0, ans, prices[i] - mn});
			if (prices[i] < mn)
				mn = prices[i];
		}
		return ans;
	}
};
