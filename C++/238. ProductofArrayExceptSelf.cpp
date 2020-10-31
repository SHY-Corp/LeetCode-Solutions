/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int mul=1,zero=0;
        for(int j =0;j<nums.size();j++){
                mul=mul*nums[j];
                if(nums[j]==0)zero++;
            }
            if(mul!=0){
            for(int i=0;i<nums.size();i++){    
                int a = mul/nums[i];
                ans.push_back(a);}
        return ans;}
        else if(zero==1){
            int b=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                b=b*nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)ans.push_back(b);
            else ans.push_back(0);
        }
        return ans;}
        else{
            for(int i=0;i<nums.size();i++){
                ans.push_back(0);
            }
            return ans;
        }
    }
};