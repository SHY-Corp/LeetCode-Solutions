
/*
Title: Capacity To Ship Packages Within D Days
Problem Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
Description: A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
*/


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n=weights.size();
        int m=*max_element(weights.begin(),weights.end());
        long long int sum=0;
        for(int i=0;i<n;i++)
            sum+=weights[i];
        
        //sum is the max weight that we need to keep to ship all the packages.
        int lo=m,hi=sum;
        //predicate FFFTT, first T, predicate (val*d)>=sum
        //so the capacity of the ship could range between maximum weight of the packages and total weight of the packages
        //For each value among the possible values, we have either True/False possible based upon whether keeping that as the capacity we can ship in D days.
        //it is order given by weights
        //now each day by the order, we start shipping, and once the capacity increases, we move the package to next day and calculate total days needed
        //if <=D, True,else, False.
        
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            
            //check if mid is the capacity, how many days it would take
            int totalDays=1,capacity=0;
            //total days will start with 1 as for 1st day we are not counting
            for(int i=0;i<n;i++)
            {
                if((capacity+weights[i])>mid)
                {
                    totalDays++;
                    capacity=weights[i];
                }
                else
                    capacity+=weights[i];
            }
            
            //check of days calculated is greater or not
            //FFFFFTTT
            if(totalDays<=D)
                //True condition //need to find first true
                hi=mid;
            else
                //False
                lo=mid+1;
            
        }
        
        return hi;
        
    }
};