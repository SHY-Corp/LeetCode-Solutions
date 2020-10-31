// Problem - 1. Two Sum

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
         
                 vector<int> v;
                if(nums.size()==0)
                    return v;
                unordered_map<int,int> m;
                for(int i=0;i<nums.size();i++)
                    m[nums[i]]=i;
                for(int i=0;i<nums.size();i++)
                {
                    int x=target-nums[i];
                    if(m.find(x)!=m.end())
                    {
                        v.push_back(i);
                        v.push_back(m[x]);
                        return v;
                    }
                }
        return v;
      }
};
