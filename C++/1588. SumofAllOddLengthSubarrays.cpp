/*
   Problem Statement :
        #1588.
            Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.
            A subarray is a contiguous subsequence of the array.
            Return the sum of all odd-length subarrays of arr.

    Constraints:
            1 <= arr.length <= 100
            1 <= arr[i] <= 1000

*/

// Using the concept of continous sum ......

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
    int ans =arr[0];        
    
    for(int i=1;i<arr.size();i++)
    { 
      ans += arr[i];                // add all the value with odd length of 1
      arr[i] += arr[i-1];           // arr[i] store the sum of all the values from ith index to 0. (i.e continous sum)
      
    }
        
    int trace = arr.size()/2 , i=2;   // trace the number of different odd length group minus 1  (i.e for arr.size = 5 there will be 3 group => odd_length = {1,3,5})
        
    while(trace--)
    {
        int j=i, it = -1;
     
    while(j<arr.size())
    { 
    ans += it>=0?arr[j]-arr[it]:arr[j];    // add all the elements from odd length group to ans var.  
         
     it++;
     j++;  }
        
     i+=2;
    }
    
    return ans;
       
    }
};
