class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int consec=0;
        int result=0;
        for(int i = 0 ; i < nums.length;i++){
            if(nums[i]==1){
                consec++;
                if(result<consec){
                    result=consec;
                }
            }else {
                consec=0;
            }
        }
        return result;
    }
}
