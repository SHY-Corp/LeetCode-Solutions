//Assigned #1016 
//CODE

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int,greater<int>> s;
        vector<int> v;//return result vector
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);//insert in a set for distinct condition
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(s.count(i)==0)
            {
                v.push_back(i);//push the numbers with zero frequency
            }
        }
        return v;
        
    }
};
