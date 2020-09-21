class Solution {
    
    int findDigit(int n){
        int result=0;
        while(n/10 > 0){
            n=n/10;
            result++;
        }
        return result-1;
    }
    
    public int findNumbers(int[] nums) {
        
        int count=0;
        int len=0;
        for(int i = 0 ; i < nums.length ; i++){
            len=findDigit(nums[i]);
            if(len%2 == 0){
                count++;
            }
        }
        return count;
    }
}
