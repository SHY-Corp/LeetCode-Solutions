/* 

In this problem, we are supposed to find out the next possible permutation of the given array of integers.

These are the steps which we will follow to solve this problem.

1) If the given array of integers is already in the decreasing order, then there would be no possible next permutation and we are
 supposed to rearrange it to the lowest possible order.
2) Else, we need to find out the first integer from the right which violates this rule i.e which is not in the decreasing order
 (let the index of this element be i) and swap this with the smallest integer to the right of it which is greater than the number
 at index i.
3) Finally, we need to reverse all the elements from the index i+1 to the end to get the next possible permutation.

*/




class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int l = nums.size();
        int i = l-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        if(i<0){
            int le = 0,re = l-1;
            while(le<re){
                int temp = nums[le];
                nums[le] = nums[re];
                nums[re] = temp;
                le++;
                re--;
                
            }
            for(int o = l-1;o>=0;o--){
                cout<<nums[o]<<" ";
            }
            
            
        }
        else{
        int left = i+1;
        int right = l-1;
        int mid;
        int idx;
        while(left<=right){
            mid = (left+right)>>1;
            if(nums[mid]<=nums[i]){
                right = mid-1;
            }
            else{
                left = mid+1;
                idx = mid;
            }
        }
        
        int temp = nums[idx];
        nums[idx] = nums[i];
        nums[i] = temp;
        int h = i+1;
        int r = l-1;
        while(h<r){
            int tem = nums[r];
            nums[r] = nums[h];
            nums[h] = tem;
            
            h++;
            r--;
        }
        
        for(int j=0;j<l;j++){
                cout<<nums[j]<<" ";
            }
        
        
        }
        
        
        
    }
};