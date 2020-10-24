class Solution {
    public int xorOperation(int n, int start) {
        int nums[]=new int[n];
        int i,bit=0;
        for(i=0;i<nums.length;i++) nums[i]=start+2*i;
        for(i=0;i<nums.length;i++) bit^=nums[i];
        return bit;
    }
}