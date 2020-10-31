/*
Title: Find in Mountain Array
Link: https://leetcode.com/problems/find-in-mountain-array/
Description: You may recall that an array A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.  If such an index doesn't exist, return -1.

You can't access the mountain array directly.  You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.

*/


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //find the peak
        int n=mountainArr.length();
        int lo=0,hi=n-1;
        //Peak Point refers to the point where value to the
        //left is greater and right is lesser
        //left is lesser and right is greater
        
        //mountain array has 3 halves incresing and decreasing
        //if target is at the peak point, then it is the minimum.
        //find the peak point
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            int first=mountainArr.get(mid);
            int second=mountainArr.get(mid+1);
            //Here if in the decreasing phase, then if peak point is the target, the it is minimum
            if(first>second)
                hi=mid;
            else lo=mid+1;
        }
        int pkPoint=lo, pkVal=mountainArr.get(lo);
        //if it is the target, the return
        if(pkVal==target)
            return pkPoint;
        
        //else, find the minimum by checking left and right
        else{
            int l1=0,r1=pkPoint-1;
            //first find in left half
            //TTFFF, First F, predicate=x<target
            while(l1<r1)
            {
                int mid=l1+(r1-l1)/2;
                int val=mountainArr.get(mid);
                if(val<target)
                    l1=mid+1;
                else
                    r1=mid;   
            }
            if(mountainArr.get(l1)==target)
                return l1;
            else
            {
                int l2=pkPoint+1,r2=n-1;
                //TTTTFF,first F, predicate = num>target
                while(l2<r2)
                {
                    int mid=l2+(r2-l2)/2;
                    if(mountainArr.get(mid)>target)
                        l2=mid+1;
                    else
                        r2=mid;
                }
                if(mountainArr.get(l2)==target)
                    return l2;
            }
        }
        return -1;
    }
};