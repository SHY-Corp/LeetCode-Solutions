// Sorted the array and found out if the count of the element becomes more than n/2, and returned it.

int majorityElement(vector<int>& nums) {
    int j;
    sort(nums.begin(),nums.end());
    int c=1;
    int n=nums.size();
    for(int i=0;i<n-1;i++)
    {
        if(nums[i+1]==nums[i])
            c++;
        else c=1;
        if(c>n/2)
        {
            j=i;
            return nums[j];
        }
    }
    return nums[j];
}
