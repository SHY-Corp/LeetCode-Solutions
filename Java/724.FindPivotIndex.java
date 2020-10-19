// Problem Link: https://leetcode.com/problems/find-pivot-index/
// Given a array nums[], we need to find the leftmost pivot index
//a pivot index is one where the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index.

/*Solution idea:
1. For a particular index i, if prefix sum till (i-1)th index equal to suffix sum till (i+1)th index, then we found our pivot index i

2. First check if the 0th index is the pivot index because we need to find out the leftmost pivot index

3. if the pivot index is 0th index,there is no prefix sum, then (suff[1]) must be equal to 0 for pivot index
    eg: nums[]=[5,2,-4,2]
        suff[]=[5,0,-2,2]
4. If there is no pivot index till (n-2)th index, we check for the last index i.e (n-1)th index
5. For last index, there is no concept of suffix sum, so for pivot index to be n-1, pre[n-2] must be equal to 0.
   eg: nums[]=[2,6,-8,1]
        pre[]=[2,8,0,1]
*/

class Solution {
    public int pivotIndex(int[] nums) {
        int n=nums.length;//length of array
        
        //if array length is 0
        if(n==0)
            return -1;
    
        int pre[]=new int[n];// prefix sum array
        int suff[]=new int[n];//suffix sum array
        
        pre[0]=nums[0];// base case
        suff[n-1]=nums[n-1];//base case
        
        //calculating prefix sum
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+nums[i];
        
        //calculating suffix sum
        for(int i=n-2;i>=0;i--)
            suff[i]=suff[i+1]+nums[i];
        
        //for 0th index, 
        if(suff[1]==0)
            return 0;
        
        for(int i=1;i<n-1;i++)
        {
            if(pre[i-1]==suff[i+1])
                return i;
        }
        
        //end of array
        if(pre[n-2]==0)
            return n-1;
        
        //no such index
        return -1;
        
    }
}
