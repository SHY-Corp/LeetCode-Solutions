class Solution
{
    public:

    bool dfs(vector<int> &nums, vector<int> taken, int idx,int k,int currSum,int targetSum)
    {
        if(k==1)
        {
            return true;
        }
        if(currSum==targetSum)
        {
            return dfs(nums,taken,0,k-1,0,targetSum);
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(!taken[i])
            {
                taken[i]=true;
                if(dfs(nums,taken,i+1,k,currSum+nums[i],targetSum))
                {
                    return true;
                }
                taken[i]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        vector<int>taken(nums.size(),false);
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
        }
        if(sum%k!=0)
        {
            return false;
        }
        return dfs(nums,taken,0,k,0,sum/k);
    }
};
