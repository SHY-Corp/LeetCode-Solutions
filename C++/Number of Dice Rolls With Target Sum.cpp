class Solution {
    
public:
     vector<vector<int> >dp;
    
    int numRollsToTarget(int d, int f, int target) {
       dp.resize(d+1,vector<int>(target+1,-1));
        return rollsrequired(d,f,target);
    }
    
    int rollsrequired(int d, int f, int target)
    {
      if(target<d || target>f*d)
      {
          return 0;
      }
      else if(d==1)
      {
          return (target<=f)?1:0;
          
      }
      else if(d==0 && target==0)
      {
          return 1;
      }
      else if(d==0 || target<0)
      {
          return 0;
      }
        if(dp[d][target]==-1)
        {
            int ans=0;
            for(int i=1;i<=f;i++)
            {
                ans+=rollsrequired(d-1,f,target-i);
               ans%=1000000007;
            }
            dp[d][target]=ans;
        }
        return dp[d][target];
    }
};
