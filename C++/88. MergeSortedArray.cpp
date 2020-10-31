class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i=0, j=0;
      vector<int> nums3;
      if(m==0 && n!=0)
      {
            nums1.clear();
            nums1 = nums2;
      }
      else if(m!=0 && n==0);
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
        nums1.clear();
        nums1 = nums3;
      }
    }
};
