//Find all unique quadruplets in the array which gives the sum of target

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (unsigned int i=0; i<nums.size(); i++) {
        if (i>0 && nums[i]==nums[i-1])
            continue; // avoid duplication for i
        for (unsigned int j=i+1; j<nums.size(); j++) {
            if (j>i+1 && nums[j]==nums[j-1])
                continue; // avoid duplication for j
            int l = j+1, r = nums.size()-1;
            while (l < r) {
                int s = nums[i]+nums[j]+nums[l]+nums[r];
                if (s > target)
                    r--;
                else if (s < target)
                    l++;
                else {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    while (l < r && nums[l]==nums[l+1])
                        l++; // avoid duplication for l
                    while (l < r && nums[r]==nums[r-1])
                        r--; // avoid duplication for r
                    l++; r--;
                }
            }
        }
     }
     return res;
}
};