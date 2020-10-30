/*
https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        int n=piles.size(),sum=0;
        sort(piles.begin(),piles.end());
        for(int i=n-2;i>=(n/3);i-=2)
        {
            //cout<<piles[i]<<" ";
            sum+=piles[i];
        }
        return sum;
    }
};
