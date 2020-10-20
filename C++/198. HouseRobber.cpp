/*198. House Robber

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint stopping
you from robbing each of them is that adjacent houses have security system
connected and it will automatically contact the police if two adjacent houses
were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each
house, determine the maximum amount of money you can rob tonight without
alerting the police.

For Example :

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/
/*class Solution {
public:
    int rob(vector<int>& nums) {
        int odds = 0;
        int evens = 0;
        for (int i = 0; i < std::size(nums); i++) {
            if (i % 2) {
                evens += nums[i];
            } else {
                odds += nums[i];
            }
        }
        return std::max(odds, evens);
    }
};*/
// this code note work in if nums=[2,1,1,2]  your output was come 3 and expected output was 4
//below code was right
class Solution {
public:
   int rob(vector<int>& nums) {
        int n=nums.size();
          if(n==0)
            return 0;
          if(n==1)
              return nums[0];
          if(n==2)
              return max(nums[0],nums[1]);
         int t[n];
         t[0]=nums[0];
       t[1]=max(nums[0],nums[1]);
       for(int i=2;i<n;i++)
       {
           t[i]=max(nums[i]+t[i-2],t[i-1]);
       }
       for(int i=0;i<n;i++)
           cout<<t[i]<<" ";
         cout<<endl;
              
        return t[n-1];
    }
};
