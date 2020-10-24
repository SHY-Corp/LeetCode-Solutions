/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.


*/


#include<bits/stdc++.h>

using namespace std;
 vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        set<vector<int>>s;     
        set<int>elements; 
        
        for(int i=0;i<nums.size();i++){
            int a=nums[i];            
            if(elements.find(a)!=elements.end())
                continue;
            elements.insert(a);
            int low=i+1, high=nums.size()-1;
            while(low<high){
                int sum=a+nums[low]+nums[high];
                if(sum==0){
                    vector<int>ans;
                    ans.push_back(a);
                    ans.push_back(nums[low]);
                    ans.push_back(nums[high]);
                    if(s.find(ans)==s.end())
                    {   res.push_back(ans);
                        s.insert(ans);
						for(const int&k : ans) cout<<k;
						cout<<"\n";
                    }
                    low++;high--;
                }
                else if(sum>0){
                    high--;
                }
                else
                    low++;
            }
        }
        return res;
		
    }
int main(){
ios_base::sync_with_stdio(false); cin.tie(0);
cout.precision(10); cout<<fixed;
vector<int> nums = {-1,0,1,2,-1,-4};
threeSum(nums);


return 0;
}
