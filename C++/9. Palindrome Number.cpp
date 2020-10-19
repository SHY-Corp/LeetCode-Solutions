/*To determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.*/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) // to check whether x is negative
            return false;

        // for positive x values

        // Storing digits of x into vector a
        vector<int> a; // declaration of vector a
        while (x != 0)
        {
            a.push_back(x % 10);
            x = x / 10;
        }

        bool flag = true;
        int n = a.size();
        for (int i = 0; i < n / 2; i++) // start of loop
        {
            if (a[i] != a[n - i - 1])
            {
                flag = false;
                break; // breaks from the loop when x is not palindrome
            }
        }

        return flag;
    }
};
