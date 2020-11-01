 /*
        Problem #1283 "Find the Smallest Divisor Given a Threshold"
        Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
        Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and               divide all the array by it and sum the result of the division. Find the smallest divisor such that the result         mentioned above is less than or equal to threshold.

        Each result of division is rounded to the nearest integer greater than or equal to that element. (For                 example: 7/3 = 3 and 10/2 = 5).
        Input: nums = [1,2,5,9], threshold = 6
        Output: 5
        Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
        If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 


        */
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       
        //To find the smallest Divisor, among set of the possible divisors from 1 to max(nums)
        //max(nums) is the max element in the nums array
        //Why max? Because any number greater than that also will give total sum the same as n, 1 for every element
        //Here for array of 1 2 3 4 .... max
        //For some of the initial it might evaluate to false, "False" means sum is greater, we need to find
        //such first number where it is true
        //we apply binary framework for elements from 1 to max
        int n=nums.size();
        int max_num=*max_element(nums.begin(),nums.end());
        int lo=1, hi=max_num;
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            //find res considering mid as the divisor
            int res=0;
            for(int i=0;i<n;i++)
                res+=ceil(nums[i]/(float)mid);
            
            //check if res is greater or not \
            //array expressed as FFFF TTTT
            if(res<=threshold)
            //mid evalautes to true, i.e.., sum <= threshold
                //since this might be it
                hi=mid;
            else
                //it is False, so leave FFFFTT, so leave this and trailing F
                lo=mid+1;
        }
        //lo points to the first true, since we keep pushing towards T, and when 
        //lo high meet, it is true!
        return lo;
    }
};