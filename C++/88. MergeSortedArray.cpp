/*
Problem-
   Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Approach-
   1] Creating new temporary vector num3, declaring position elements for nums1 and nums2 as i and j.
   2] Using the loop comparing element of nums1 with nums2 and pushing the smallest of them into that temporary vector nums3.
   3] Increasing the respective positional element of the vector with smallest element.
   4] When any of the i and j become equal to the length of their vector, then appending all the elements of other vector in nums3 and breaking the loop.
   5] Finally, we will get our merged array in nums3.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i=0, j=0;
      vector<int> nums3;
      if(m==0 && n!=0)               //if nums1 is empty then copying nums2 in nums1
      {
            nums1.clear();
            nums1 = nums2;
      }
      else if(m!=0 && n==0);         //if nums2 is empty then pass
      else
      {
            while(1)
          {
            if(nums1[i]<nums2[j])
            {
                nums3.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums3.push_back(nums2[j]);
                j++;
            }
            if(i == m)
            {
                while(j<n)
                {
                    nums3.push_back(nums2[j]);
                    j++;
                }
                break;
            }
            else if(j == n)
            {
                while(i<m)
                {
                    nums3.push_back(nums1[i]);
                    i++;
                }
                break;
            }
          }
        nums1.clear();        // making nums1 empty
        nums1 = nums3;        // copying nums3(temporary vector) in nums1
      }
    }
};
