class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return n;

        int a = 0, b = 1, sum = 0;
        while (n > 0)
        {
            sum = a + b;
            a = b;
            b = sum;
            n--;
        }
        return sum;
    }
};
