/*
53 | Maximum Subarray | EASY

Problem Description:
Given an array of integers, find the contiguous subarray which has the largest
sum.

Constraints:
- preferrably O(n) Solution
- use as little memory and time
- the array of integers may include negative integers as well!
- a contiguous subarray must have atleast one element

Solution explained: Divide and Conquer Approach
In this approach, imagine a tree based divide and conquer solution(along the lines
of merge sort) to break down the array, and find the maximum sum.
This is a recursive approach and at each call made to maxSubArr():
  1. Find the maximum sum in the left half
  2. Find the maximum sum in the right half
  3. Find the maximum sum across the mid point of the array
    using maxCrossArr():
      -Include the mid point and keep adding elements in the left direction to
      the sum. Store the max of these values in lsum.
      -Repeat the same on the right side and store rsum
      -return lsum+rsum as the maximum that can be obtained across the mid point
        of the array.

  return the max of the 3 values computed above
*/

class Solution {
public:
    int maxCrossArr(vector<int> &v, int m, int l, int h){
      //find the maximum sum across the mid point

        int lsum=INT_MIN;
        int rsum=INT_MIN;

        //include the mid point while calculating lsum as it must go across the
        //middle of the array
        int sum=0;
        for(int i=m;i>=l;i--){
            sum+=v[i];
            lsum=max(lsum, sum);
        }

        sum=0;
        for(int j=m+1;j<=h;j++){
            sum+=v[j];
            rsum=max(rsum,sum);
        }
        return lsum+rsum;
    }

    int maxSubArr(vector<int> &v, int l, int h){
        //boundary cases(the array does not exist or the array contains a single element)
        if(l>h) return 0;
        if(l==h)   return v[l];

        //mid point of the array
        int m=(l+h)/2;

        //compute max sum across left half
        int m1=maxSubArr(v, l, m);

        //compute max sum across right half
        int m2=maxSubArr(v, m+1, h);

        //compute max sum across the mid point  
        int m3=maxCrossArr(v, m, l ,h);

        return max( m1, max(m2,m3));
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArr(nums, 0, nums.size()-1);
    }
};
