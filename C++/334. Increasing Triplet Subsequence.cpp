//Problem
/* Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.*/

//Approach
/* We maintain first lowest and second lowest found till now, notice these values will always be set to some values from the nums array before we reach a returning point. If we ever find an integer that is greater than first_lowest and second_lowest, we return true, because this is our set of 3 integers*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_lowest = INT_MAX, second_lowest = INT_MAX;
        for(int integer : nums)
        {
            if(integer <= first_lowest)
            {
                first_lowest = integer; //This will keep getting updated and set to the lowest first value we have
            }
            else if(integer <= second_lowest)
            {
                second_lowest = integer; //This will keep getting updated and set to the lowest second value we have
            }
            else
            {
                return true; //If we find a value greater than first lowest and second lowest, we are done
            }
        }
        return false;
    }
};
