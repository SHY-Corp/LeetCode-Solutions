class NumArray {
public:
    vector<int> num,nums2;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        num.resize(n+1);
        nums2.resize(n,0);
        for(int i=0;i<n;i++)
            update(i,nums[i]);
    }
    
    void update(int index, int val) {
        int curr=val-nums2[index];
        nums2[index]=val;
        index++;
        for(;index<=n;index+=index&(-index) ) 
            num[index]+=curr;
    }
    
    int getsum(int left)
    {
        int sum=0;
        for(;left>0;left-=(left&(-left)) )
            sum+=num[left];
        return sum;
    }
    
    int sumRange(int left, int right) {
        return getsum(right+1)-getsum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
