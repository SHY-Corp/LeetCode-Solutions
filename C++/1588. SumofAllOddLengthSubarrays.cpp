/*
   Problem Statement :
        #1588.
            Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.
            A subarray is a contiguous subsequence of the array.
            Return the sum of all odd-length subarrays of arr.

    Constraints:
            1 <= arr.length <= 100
            1 <= arr[i] <= 1000

    Approach:
            Create a window of odd length , in each window take the sum uptil the window size. For first outermost loop iteration
            the size is 1 henceafter 3 , 5 , 7 and so on. We basically enumerate all possible odd length subarrays.

*/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0,n=arr.size(),i;
        for(i =0;i<n;i++)
		{
            int contribution = ceil((i+1)*(n-i)/2.0);
            ans+=(contribution*arr[i]);
        }
        return ans;
    }
};
