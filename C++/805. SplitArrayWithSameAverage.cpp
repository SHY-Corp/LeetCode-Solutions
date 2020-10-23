/**In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)

Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.

Example :
Input: 
[1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
Note:

The length of  A will be in the range [1, 30].
A[i] will be in the range of  [0, 10000].
 

This question gave us an array A, asking whether we can divide the array into two small arrays, and the average value of the two arrays must be the same.
There is an implicit condition that the average value of the entire array is also equal to the average value of the two arrays.
Since the average value is obtained by dividing the sum of numbers by the number,
suppose that the entire array has n arrays, and the sum of numbers is sum, and one of the arrays is divided into k, then the other array is (n-k).
If the sum of numbers is sum1, the sum of the array is sum2, there is the following equation:

sum / n = sum1 / k = sum2 / (n-k)

The problem here is how to find any k numbers in the array so that the sum is a given value. 
First, add a 0 to dp[0], this is to prevent crossing the boundary. The idea of ​​updating dp[i] is to add a new number to each number in dp[i-1],
so the outermost for loop traverses each number in the original array, and the middle for loop traverses k, from n/2 to 1,
and then the innermost for loop traverses all the arrays in dp[i-1], plus the number traversed by the outermost layer, and stores it in dp [i] That's it.
For each value of k, verify that if sum * k / n == 0 is established and sum * i / n exists in dp[i], return true.
If it is not established at the end, return false, see the code as follows:
*/


class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(), m = n / 2, sum = accumulate(A.begin(), A.end(), 0);
        bool possible = false;
        for (int i = 1; i <= m && !possible; ++i) {
            if (sum * i % n == 0) possible = true;
        }
        if (!possible) return false;
        vector<unordered_set<int>> dp(m + 1);
        dp[0].insert(0);
        for (int num : A) {
            for (int i = m; i >= 1; --i) {
                for (auto a : dp[i - 1]) {
                    dp[i].insert(a + num);
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (sum * i % n == 0 && dp[i].count(sum * i / n)) return true;
        }
        return false;
    }
};
