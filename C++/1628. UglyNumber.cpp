// program to find nth Ugly Number
/* Ugly numbers are numbers whose only prime factors are 2, 3, 5 */

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(1, 1);   
        // Intiliaze with 1
        n -= 1;
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        int nextNum = 0;
        

        while (n--)
        {
            int num2 = dp[index2] * 2;
            int num3 = dp[index3] * 3; // Multiply the ugly number with 2,3,5
            int num5 = dp[index5] * 5;
            //Minimun to get sorted List
            nextNum = min({num2, num3, num5});  

           
            if (nextNum == num2)
            {
                index2++;
            }
            if (nextNum == num3)
            {
                index3++;
            }
            if (nextNum == num5)
            {
                index5++;
            }
            dp.push_back(nextNum); //Each time, we take the least of multiple of 2, 3, 5 and keep pushing ugly number in the array
        }
        return dp.back();
    }
};
