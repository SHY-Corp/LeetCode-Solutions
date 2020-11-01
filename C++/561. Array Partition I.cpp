/*Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum. */
class Solution {
public:
    int arrayPairSum(vector<int>& a) {
        sort(a.begin(), a.end());
        long long int sum = 0, i;
        for (i = 0; i < a.size(); i += 2)
            sum += a[i];
        return sum;
    }
};