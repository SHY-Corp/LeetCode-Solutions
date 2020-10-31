/*
    Problem Statement:
        Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
        Find the kth positive integer that is missing from this array.
    Constraints:
        1 <= arr.length <= 1000
        1 <= arr[i] <= 1000
        1 <= k <= 1000
        arr[i] < arr[j] for 1 <= i < j <= arr.length
    Approach:
        Let's assume that no element is present in the array. In this case, answer should be equal to k.
        Now we traverse through the array in linear time.
        For every element we encounter having its value greater than answer, we increment our answer by one
*/

//Solution:

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = k;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= ans)
                ans++;
        }
        return ans;
    }
};

