/**
 * You have d dice, and each die has f faces numbered 1, 2, ..., f.
 * Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target
 * 
 * 
 * Approach :
 * 
 * We take hold of one die and roll all the numbers for it, mean while recursing through possibilities of all other dice.
 * We TABULATE the data on number of Possibilities as a function of (number of dice , Target value)
 */
class Solution
{
    int mod = 1e9 + 7;
    int rollCount(int d, int f, int target, vector<vector<int>> &store)
    {
        if (store[d][target] > -1)
            return store[d][target];

        if (d == 1)
        {
            if (f >= target)
                return 1;
            else
                return 0;
        }

        long sum = 0;

        for (int i = 1; i <= f && i <= target - d + 1; i++)
        {
            sum += rollCount(d - 1, f, target - i, store);
        }
        store[d][target] = sum % mod;
        return sum % mod;
    }

public:
    int numRollsToTarget(int d, int f, int target)
    {
        vector<vector<int>> vec(d + 1, vector<int>(target + 1, -1));

        return this->rollCount(d, f, target, vec);
    }
};