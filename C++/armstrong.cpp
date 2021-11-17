/**
 * @file armstrong.cpp
 * @author Vipul Kumar Singh
 * @brief
 * @version 0.1
 * @date 2021-11-17
 * @copyright Copyright (c) 2021
 */

class Solution
{
public:
    bool isArmstrong(int n)
    {
        int n_temp = n; // to store the value of n
        int temp = 0;   // temperary variable
        int solution = 0; // to store the solution to check for armstrong or not

        while (n_temp > 0)
        {
            temp = n_temp % 10;           // its give the modulus of the number
            solution += temp * temp * temp; // to gets its cube to further calculation
            n_temp = n_temp / 10;
        }

        if (solution == n)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
};