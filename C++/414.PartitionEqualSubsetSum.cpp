//Given a non-empty array containing only positive integers, 
//find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//This program checks whether it has qual sum or not
class Solution {
public:
    int dp[202][20000];
    bool check(vector<int>& nums,int sum,int n)
    {
        if(n==0)return false;
        if(sum==0)return true;
        if(dp[n][sum]!=-1)return dp[n][sum];
        if(sum>=nums[n-1])
            return dp[n][sum]=check(nums,sum-nums[n-1],n-1)|| check(nums,sum,n-1);
        else
            return dp[n][sum]=check(nums,sum,n-1);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2!=0)return false;
        return check(nums,sum/2,n);
    }
};