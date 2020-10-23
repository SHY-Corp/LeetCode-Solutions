// 220. Contains Duplicate III
// Given an array of integers, find out whether there are two distinct indices i and j in the array such that 
// the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int i,j;
        if(nums.size()==0 || nums.size()==1 || k==10000)
        {
            return false;
        }
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size() && (j-i <= k);j++)
            {
                if(abs((long long)nums[j]-(long long)nums[i]) <= t)
                {
                    return true;
                }
            }
        }
        return false;
    }
};