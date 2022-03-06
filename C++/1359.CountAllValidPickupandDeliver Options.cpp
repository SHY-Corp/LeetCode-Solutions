class Solution {
public:
    int countOrders(int n) {
        long ways = 1;
        int MOD = 1e9 + 7;

        for(int i=1; i<=n; i++)
        {
            //ways to arrange pickups
            ways = ways * i;

            //ways to arrange deliveries
            ways = ways * (2*i - 1);

            //to avoid overflow as mentioned in the description.
            ways = ways % MOD;
        }

        return ways;
    }
};

/*
Dry run with an example:

n = 3
No. of pickups = 3
No. of deliveries = 3
So, we will have 6 slots to arrange the pickup and delivery.

=> Order doesn't matter while pickup so they can be arranged in any sequence.
   -3 pickups can be arranged in 3! ways.

    Let's say for now we take  P2 P3 P1 _ _ _

=> Order MATTERS while delivering, so they can only come after they have been picked up!
   - Last picked up order = P1
   - D1 can only come after P1, so it can only be arranged in 1 way

     P2 P3 P1 D1

   - 2nd last picked up order = P3
   - D3 can only come after P3, so let's see how it can be arranged

     P2 P3 _ P1 _ D1 _     , so D3 can be arranged in 3 ways

   - Remaining picked up order = P2
   - No. of ways D2 can be arranged so it comes after P2

     P2 _P3 _ P1 _ D1 _ D3 _  , D2 can be arranged in 5 ways!

     ---------------------------------------------------------
     Total valid sequences = 3! * (5 * 3 * 1) = 6 * (15) = 90
     ---------------------------------------------------------

*/
