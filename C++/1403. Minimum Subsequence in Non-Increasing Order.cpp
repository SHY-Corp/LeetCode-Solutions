/*Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence. 

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 

Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order. */
class Solution {
public:
    vector<int> minSubsequence(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<int> v;
        int i, sum = 0, p = 0;
        for (i = 0; i < a.size(); i++)
            sum += a[i];
        for (i = a.size() - 1; i >= 0; i--)
        {
            if (p > (sum - p))
                break;
            else
            {
                p += a[i];
                v.push_back(a[i]);
            }
        }
        return v;
    }
};