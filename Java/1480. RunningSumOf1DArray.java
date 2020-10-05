

class Solution {
    public int[] runningSum(int[] nums) {
        int a = 0;
        int res [] = new int[nums.length];
        int i;
        for (i = 0; i < nums.length; i++) {
            res[i] = a + nums[i]; 
            a=res[i];
        }
        
        return res;
    }

}
