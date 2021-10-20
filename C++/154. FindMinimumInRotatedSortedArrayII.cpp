/*
    154. Find Minimum in Rotated Sorted Array II

    Many people think we need to do binary search or magic. But the best solution is to simply just
    search trough the array in O(n) time. 

    Read this discussion: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/48849/Stop-wasting-your-time.-It-most-likely-has-to-be-O(n).
*/

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int smol = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < smol) {
                smol = nums[i];
            }
        }
        return smol;
    }
};