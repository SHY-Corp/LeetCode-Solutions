class Solution {

    public int findMaximumXOR(int[] nums) {
        Arrays.sort(nums);
        int or = 0;
        for (int n : nums) {
            or |= n;
        }
        int maxXor = 0;
        int i = 0, j = nums.length - 1;
        while (i < j) {
            maxXor = Math.max(maxXor, nums[i] ^ nums[j]);
            if (( or ^ nums[i]) > nums[j])  i++;
            else j--;
        }
        return maxXor;
    }

}