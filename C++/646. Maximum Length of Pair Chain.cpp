class Solution {
public:
    
   static bool cmp(vector<int> &j1, vector<int> &j2)
    {
       //gives wrong with <=
       return j1[1] < j2[1];    
    }
    
    int findLongestChain(vector<vector<int>>& job) 
    {
        
        int n=job.size();
        
        sort(job.begin(),job.end(),cmp);
        
        int ans= 1;
        int i=0;
        
        for(int j=1;j<n;j++)
        {
            if(job[i][1]<job[j][0])//if 2-3 and 3-4 allowed, then put <= as well
            {
                ans++;
                i=j;//make  j the new latest selected job- so compare with its end time to allow other
            }
        }
        
        return ans;
        
        
    }
};