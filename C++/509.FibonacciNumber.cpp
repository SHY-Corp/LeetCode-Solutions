class Solution {
public:
    //Time Complexity : O(N), each fibonacci number is only calculated once.
    //Space Complexity : O(1), only constant space is being used.

    int fib(int n) {
        //handling base cases
        if(n==0)
            return 0;
        if(n==1)
            return 1;

        //maintaining 3 variables: 1st one will store 0, 2nd will store 1 and 3rd will be updated with 2nd val
        int prev2Val = 0;
        int prev1Val = 1;
        int currVal = prev1Val;

        //iterating from 2 to n and calculating the current fibonacci value with the sum of previous 2 numbers
        //and updating the remaining 2 variables subsequently
        for(int i=2; i<=n; i++)
        {
            currVal = prev1Val + prev2Val;
            prev2Val = prev1Val;
            prev1Val = currVal;
        }
        //current value will hold the fibonacci value
        return currVal;
    }
};

/*   //TC = SC = O(n)
class Solution {
public:
    unordered_map<int, int> dp;
    int fib(int n) {
        dp[0] = 0;
        if(n==1 || n==2)
            return 1;

        if(dp.find(n)==dp.end())
        {
            dp[n] = fib(n-1) + fib(n-2);
        }
        return dp[n];
    }
};
*/
