//If k==0,check how many number of elements are repeated
/*Else for each unique number num in the set of given integers check whether num+k is present.If it is there,then increment finalval*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<int> s;
        int n=nums.size(),fval=0;
        for(int i=0;i<n;i++)
         s.insert(nums[i]);
        if(k==0)
        {
           map<int,int> mp;
            for(int i=0;i<n;i++)
            {
              mp[nums[i]]++;
                if(mp[nums[i]]==2)
                {
                    fval++;
                }
            }
            return fval;
        }
        set<int> ::iterator it;
        for(it=s.begin();it!=s.end();it++)
        {
            int val=(*it);
           
                if(s.find(k+val)!=s.end())
                    fval++;
            
        }
        return fval;
    }
};
