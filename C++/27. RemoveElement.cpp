class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int a=0;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(nums[i]==val)    a++;
            else    v.push_back(nums[i]);
        }
        nums = v;
        return n-a;
    }
};