// Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise.
// Return the number of negative numbers in grid.
//Runtime beats 94.52% of cpp submission

// Key is to find the first positive number in each row
// Using upper_bound() / binary search we can do this easily

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int ans(0);
        for (const vector<int> &row : grid)
            ans += upper_bound(row.rbegin(), row.rend(), -1) - row.rbegin();
        return ans;
    }
};