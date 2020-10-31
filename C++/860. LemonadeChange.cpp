/*At a lemonade stand, each lemonade costs $5. 

Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).

Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.

Note that you don't have any change in hand at first.

Return true if and only if you can provide every customer with correct change.*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0, c20 = 0, i;
        for (i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                c5++;
            else if (bills[i] == 10)
            {
                c10++;
                c5--;
            }
            else
            {
                c20++;
                if (c10 != 0)
                {
                    c10--;
                    c5--;
                }
                else
                    c5 = c5 - 3;
            }
            if (c5 < 0 || c10 < 0)
                return false;
        }

        return true;
    }
};