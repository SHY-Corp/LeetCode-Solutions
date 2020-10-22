/*
  Given an array for 0s and 1s 
  we have to find maximum number of consecutive ones
  return the max number of ones (int)
*/

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int i = 0;
        int maxi = 0;
        while (i < nums.size())
        {
            if (nums[i] == 0)
            {
                i++;
            }
            else
            {
                int j = i;
                while (j < nums.size() && nums[j] == 1)
                {
                    j++;
                }
                maxi = max(maxi, j - i);
                i = j;
            }
        }
        return maxi;
    }
};