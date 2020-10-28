/*
Find the index of peak in a mountain array.(It is guaranteed that the given array is mountain array.)

Definition of Mountain Array:
    arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
    arr[0] < arr[1] < ... arr[i-1] < arr[i]
    arr[i] > arr[i+1] > ... > arr[arr.length - 1]

*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        // Using Binary Search
        // First T
        // FFFTT
        // p(x) : A[x] > A[x+1]
        
        int n =  A.size();
        int lo,hi,mid;
        
        lo=0,hi=n-1;
        while(lo<hi){
            mid= lo+(hi-lo)/2;
            if(A[mid]>A[mid+1]){
                hi=mid;
            }
            else {
                lo=mid+1;
            }
        }
        
        return lo;
    }
};