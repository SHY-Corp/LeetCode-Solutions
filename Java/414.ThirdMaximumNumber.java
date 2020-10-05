import java.util.Arrays;
class Solution {
    public int thirdMax(int[] nums) {
        int fmax, smax, tmax;
        int len=nums.length;
        boolean flag=false;
        fmax=Integer.MIN_VALUE;
        smax=Integer.MIN_VALUE;
        tmax=Integer.MIN_VALUE;
        
        for(int i=0;i<len;i++){
            if(nums[i]==Integer.MIN_VALUE){
                flag=true;
            }
            if(nums[i]>fmax){
                tmax=smax;
                smax=fmax;
                fmax=nums[i];
            }
            else if(nums[i]!=fmax && nums[i]>smax){
                tmax=smax;
                smax=nums[i];
            }
            else if(nums[i]!=smax && nums[i]<smax && nums[i]>tmax){
                tmax=nums[i];
            }
        }
        
        if(smax==tmax){
            return fmax;
        }else if(tmax!=Integer.MIN_VALUE || flag){
            return tmax;
        }else{
            return fmax;
        }
        
        
    }
}
