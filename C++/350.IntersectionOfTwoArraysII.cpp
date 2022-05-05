class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map<int, int> m;

        //storing the elements of nums1 into a map
        for(auto x: nums1)
            m[x]++;

        //iterating over the elments if nums2 and checking if that element exists in our map
        for(auto y: nums2)
        {
            //if it does, pushing it into the result vector and decrementing its count
            if(m[y]>0)
            {
                v.push_back(y);
                m[y]--;
            }
        }
        return v;
    }
};

/*
   TC = O(nums1.size()+nums2.size()), since we are iterating over both arrays
   SC = O(n), space used by result array
*/

/****************************************************************************************************/

//Follow-up solution:

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int n = nums1.size();
        int m = nums2.size();
        int i=0, j=0;

        //we want to traverse over the smaller vector
        if(nums1.size()>nums2.size())
            intersect(nums2, nums1);

        //sorting the 2 vectors
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));

        while(i<n && j<m)
        {
            //pushing the common element into the result vector and incrementing the pointers, if it exists
            if(nums1[i]==nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
                j++;
            }
            //incrementing the pointer of 2nd vector if the value of 1st vector is greater than 2nd vector
            else if(nums1[i]>nums2[j])
                j++;
            //otherwsie, incrementing the pointer of 1st vector
            else
                i++;
        }
        return v;
    }
};

/*
     TC: O(mlogm) + O(nlogn) + O(min(m,n)), for sorting the 2 vectors and traversing over the smaller vector
     SC: O(n), length of the result vector
     If already sorted input is provided, then two pointer approach is better than using hashmaps.
     If the larger vector cannot be loaded in memory, then binary search is a better approach.
*/
