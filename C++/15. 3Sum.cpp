class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int,int>m1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m1[nums[i]]++;
        }
        set<multiset<int>>s;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int t=-1*(nums[i]+nums[j]);
                if(nums[i]==nums[j] || t==nums[i] || t==nums[j])
                    continue;
                if(!m1.count(t))
                    continue;
                multiset<int>s1;
                s1.insert(t);
                s1.insert(nums[i]);
                s1.insert(nums[j]);
                s.insert(s1);
            }
        }
        for(auto it:m1)
        {
            if(it.second>1 && m1.count(-2*it.first) && it.first!=0)
            {
                multiset<int>s1;
                s1.insert(it.first);
                s1.insert(it.first);
                s1.insert(-2*it.first);
                s.insert(s1);
            }
        }
        if(m1.count(0) && m1[0]>2)
        {
            multiset<int>s1;
            s1.insert(0);
            s1.insert(0);
            s1.insert(0);
            s.insert(s1);
        }
        
        for(auto &it:s)
        {
            vector<int>temp;
            for(auto &it1:it)
            {
                temp.push_back(it1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};