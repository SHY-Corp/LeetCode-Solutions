/*
 * LeetCode Problem 1539. Kth Missing Positive Number
 * Url: https://leetcode.com/problems/kth-missing-positive-number/
 * Statement:
 * Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
 * Find the kth positive integer that is missing from this array.
 *
 * Example:
 * Input:  arr = [2,3,4,7,11], k = 5
 * Output: 9
 */


#include <assert.h>
#include <vector>

class Solution {
public:
    int findKthPositive(const std::vector<int> &arr, int k) {
        assert(1 <= k);
        assert(k <= 1000);
        assert(arr.size() <= 1000);
        if (arr.empty() || k < 1) {
            return -1;
        }
        if (k > arr[arr.size() - 1]) {
            return k - arr.size();
        }
        int res = 1;
        int idx = 0;
        while (k >= 0) {
            int tmp = arr[idx];
            if (res == tmp) {
                ++idx;
                res += 2;
            } else {
                ++res;
                --k;
            }
        }
        return res;
    }
};
