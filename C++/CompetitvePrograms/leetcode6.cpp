#include<iostream>
#include<vector>
using namespace std;
 int majorityElement(vector<int> nums) 
    {
    	
        int arr[1000]={0},i;
		for( i=0;i<nums.size()-1;i++)
        {
        	for(int j=i-1;j>=0;j--)
        	if(nums[j]=nums[i])
        	continue;
        	
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                    arr[i]++;
            }
            if(arr[i]+1>nums.size()/2)
                return nums[i];
        }
      return nums[i];
    }
int main()
{
	vector<int> arr(0);
	  arr.push_back(10); 
    arr.push_back(9); 
    arr.push_back(9);

	  arr.push_back(9); 
    arr.push_back(10);
	cout<<majorityElement(arr);
}

