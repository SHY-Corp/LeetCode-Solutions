/*
PROBLEM - 1561. Maximum Number of Coins You Can Get

DESCRIPTION -

There are 3n piles of coins of varying size, you and your friends will take
piles of coins as follows:
== In each step, you will choose any 3 piles of coins (not necessarily consecutive).
== Of your choice, Alice will pick the pile with the maximum number of coins.
== You will pick the next pile with maximum number of coins.
== Your friend Bob will pick the last pile.
== Repeat until there are no more piles of coins.

Given an array of integers piles where
piles[i] is the number of coins in the ith pile.
Return the maximum number of coins which you can have.

CONSTRAINTS-

3 <= piles.length <= 10^5
piles.length % 3 == 0
1 <= piles[i] <= 10^4

APPROACH-

-- We first sort the piles array as we are greedily going to assign piles.
-- Then we maintain a cnt, to track the number of piles each one will get.
-- Then from max end of array, we start assigning the piles.
-- At every odd chance we will be adding the pile to our ans so as to maximize output.

TIME COMPLEXITY-

TC of solution O(n.log.n) where n is size of piles array. (Due to sorting)

*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end()); // Sort the piles array
        int cnt = piles.size() / 3; // 3n piles hence everyone will get (3n)/3 piles
        int ans(0), curr(0);
        for (int i = piles.size() - 1; i >= 0; i--) // Start from max end
        {
            if (!cnt) break;
            if (curr & 1)       // If the current counter is odd
            {
                ans += piles[i];
                cnt--;         // 1 pile is done.
                curr++;
            }
            else curr++;
        }
        return ans;
    }
};