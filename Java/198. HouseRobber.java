/*
Since we are not allowed to rob two adjacent houses, we keep two variables pre and cur. 
During the i-th loop, pre records the maximum profit that we do not rob the i - 1-th house and thus the current house (the i-th house) can be robbed 
while cur records the profit that we have robbed the i - 1-th house.

The code is as follows.

    Java
    */


class Solution {
    public int rob(int[] nums) {
        int pre = 0, cur = 0;
        for (int num : nums) {
            final int temp = Integer.max(pre + num, cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
}
