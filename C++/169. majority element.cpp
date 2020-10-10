class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> m;
        int ans;
        
        int y=nums.size();
        
        for(int i=0;i<y;i++){
            m[nums[i]]++;
        }
        
        for(auto i=m.begin();i!=m.end();i++){
            // int n=i->first;
            if(i->second>y/2){
                ans=i->first;
            }
        }
        
        return ans;
        
    }
};