class NumArray {  
public:
    /* I am declaring a vector named 'sum' here which will be +1 greater than
       the given array. The idea is to store the sum of all the elements of
       this array appearing before the given index! So, the sum before 0th
       element would be 0, i.e. sum[0]=0. Similarly,

       sum[1]=nums[0];
       sum[2]=nums[1]+nums[0]=nums[1]+sum[1];    
       sum[3]=nums[2]+nums[1]+nums[0]=nums[2]+sum[2];   (From the above step)
       .    .     .
       .    .     .
       sum[i]=nums[i-1]+sum[i-1];

       This sum is calculated till the condition i<=n holds! We are not going beyond
       n as that's the last element in the original array.
    */
    vector<int>sum;
    NumArray(vector<int>& nums) {
       int i, n;
        n=nums.size();
        sum.resize(n+1);        //I am creating another dynamic array with n+1 space
        sum[0]=0;
        for(i=1; i<=n; i++)
        {
            sum[i]=sum[i-1]+nums[i-1];
        }
    }
    

    /* So now, the range (i,j) for which we are computing the sum, we will pick the sum till
       last element, i.e. sum(j+1) and subtract the sum till ith element, i.e. sum[i]. This 
       gives us the sum from whatever range we have picked.
    */
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */