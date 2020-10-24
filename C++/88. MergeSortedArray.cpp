/***
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array. 

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.

***/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        int count = 0;
        while(i<m+count && j<n){
            if(nums1[i] > nums2[j]){
                nums1.insert(nums1.begin() + i,1,nums2[j]);
                j++;
                count++;
                nums1.pop_back();
            }
            else
                i++;
        }
        while (j<n){
            nums1.insert(nums1.begin()+i,1,nums2[j]);
            j++;
            i++;
            nums1.pop_back();
        }
        
    }
};
